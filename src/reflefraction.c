#include "reflefraction.h"

#define ENVIRONMENT_REFRACTIVE_INDEX WATER_REFRACTIVE_INDEX

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

Vec3 get_refraction_dir(const Vec3 dir, const Vec3 normal, const double rri) {
    double cos_theta = vec3_dot(normal, vec3_mult_n(dir, -1));
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

Vec3 reflefraction_get_dir(const Vec3 dir, const HitData hit_data) {
    Material material = scene[hit_data.hittable_index].material;
    Vec3 normal = hit_data.normal;
    double relative_refraction_index, cos_theta, sin_theta, sin_theta_prime;

    switch (material.type) {
        default:
        case MATTE: return get_diffuse_reflection_dir(normal); break;
        case MIRROR: return get_specular_reflection_dir(dir, normal); break;
        case CONDUCTOR: return vec3_normalize(vec3_add(get_specular_reflection_dir(dir, normal), get_fuzzy_offset(material.fuzz)));
        case DIELECTRIC:
            if (hit_data.inside_object)
                relative_refraction_index = material.refractive_index / ENVIRONMENT_REFRACTIVE_INDEX;
            else
                relative_refraction_index = ENVIRONMENT_REFRACTIVE_INDEX / material.refractive_index;

            cos_theta = vec3_dot(normal, vec3_mult_n(dir, -1));
            sin_theta = sqrt(fabs(1 - cos_theta * cos_theta));
            sin_theta_prime = relative_refraction_index * sin_theta;

            if (fabs(sin_theta_prime) > 1) // if there is no such angle
                return get_specular_reflection_dir(dir, normal); // total internal reflection
            return get_refraction_dir(dir, normal, relative_refraction_index);
        break;
    }
}
