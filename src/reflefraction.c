#include "reflefraction.h"

Vec3 get_diffuse_reflection_dir(const Vec3 normal) {
    Vec3 reflected_dir;
    do {
        reflected_dir = vec3_add(normal, vec3_rand_unit_circle());
    } while (vec3_near_zero(reflected_dir));
    return vec3_normalize(reflected_dir);
}

Vec3 get_specular_reflection_dir(const Vec3 dir, const Vec3 normal) {
    // reflected_dir = dir - 2 * dot(normal, dir) * normal
    return vec3_sub(dir, vec3_mult_n(normal, 2 * vec3_dot(normal, dir)));
}

Vec3 get_fuzzy_offset(const double fuzz) {
    return vec3_mult_n(vec3_rand_unit_circle(), fuzz);
}

double reflectance(const double cos_theta, const double rri) {
    // use Schlick's approximation
    double r0 = (ENVIRONMENT_REFRACTIVE_INDEX - rri) / (ENVIRONMENT_REFRACTIVE_INDEX + rri);
    r0 *= r0;
    double r_theta = r0 + (1 - r0) * pow((1 - cos_theta), 5);
    return r_theta;
}

Vec3 get_refraction_dir(const Vec3 dir, const Vec3 normal, const double cos_theta, const double rri) {
    // R'⟂ = η * (R + n * cosθ)
    Vec3 refracted_dir_perp = vec3_mult_n(vec3_add(dir, vec3_mult_n(normal, cos_theta)), rri);
    // R'∥ = n * (-√(1 - |R'⟂|²))
    Vec3 refracted_dir_paral = vec3_mult_n(normal, -sqrt(fabs(1 - vec3_squared_len(refracted_dir_perp))));

    // printf(
    //     "dir={%lf %lf %lf}, normal={%lf %lf %lf}, rri=%lf, cos_theta=%lf, refracted_dir_perp={%lf %lf %lf}, refracted_dir_paral={%lf %lf %lf}\n",
    //     dir.x, dir.y, dir.z, normal.x, normal.y, normal.z, rri, cos_theta, refracted_dir_perp.x, refracted_dir_perp.y, refracted_dir_perp.z, refracted_dir_paral.x, refracted_dir_paral.y, refracted_dir_paral.z
    // );

    return vec3_normalize(vec3_add(refracted_dir_perp, refracted_dir_paral));
}

Vec3 reflefraction_get_dir(const Vec3 dir, const HitData *const hit_data) {
    Material material = scene[hit_data->hittable_index].material;
    Vec3 normal = hit_data->normal;
    double rri = material.relative_refraction_index;
    double cos_theta, sin_theta, sin_theta_prime;

    switch (material.type) {
        default:
        case MATTE: return get_diffuse_reflection_dir(normal); break;
        case MIRROR: return get_specular_reflection_dir(dir, normal); break;
        case CONDUCTOR: return vec3_normalize(vec3_add(get_specular_reflection_dir(dir, normal), get_fuzzy_offset(material.fuzz))); break;
        case DIELECTRIC:
            if (!hit_data->inside_object)
                rri = 1 / rri;
            
            cos_theta = vec3_dot(normal, vec3_mult_n(dir, -1));
            sin_theta = sqrt(fabs(1 - cos_theta * cos_theta));
            sin_theta_prime = rri * sin_theta;

            if (fabs(sin_theta_prime) > 1 || reflectance(cos_theta, rri) > rand_double(0, 1)) // if there is no such angle
                return get_specular_reflection_dir(dir, normal); // total internal reflection
            return get_refraction_dir(dir, normal, cos_theta, rri);
        break;
    }
}
