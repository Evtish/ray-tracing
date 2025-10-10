#include "reflefraction.h"

Vec3 get_diffuse_reflection_dir(const Vec3 normal) {
    Vec3 reflected_dir;
    do {
        reflected_dir = vec3_add(normal, vec3_rand_unit_circle());
    } while (vec3_near_zero(reflected_dir));
    return reflected_dir;
}

Vec3 get_specular_reflection_dir(const Vec3 dir, const Vec3 normal) {
    // reflected_dir = dir - 2 * dot(normal, dir) * normal
    return vec3_sub(dir, vec3_mult_n(normal, 2 * vec3_dot(normal, dir)));
}

Vec3 get_fuzzy_offset(const double fuzz) {
    return vec3_mult_n(vec3_rand_unit_circle(), fuzz);
}

Vec3 get_refraction_dir(const Vec3 dir, const Vec3 normal, const double rri) {
    // R'⟂ = η * (R + n * (-R * n))
    Vec3 refracted_dir_perp = vec3_mult_n(vec3_add(dir, vec3_mult_n(normal, vec3_dot(normal, vec3_mult_n(dir, -1)))), rri);
    double refracted_dir_perp_len = vec3_len(refracted_dir_perp);
    // R'∥ = n * (-√(1 - |R'⟂|²))
    Vec3 refracted_dir_paral = vec3_mult_n(normal, -sqrt(1 - refracted_dir_perp_len * refracted_dir_perp_len));
    return vec3_add(refracted_dir_perp, refracted_dir_paral);
}

Vec3 reflefraction_get_dir(const Vec3 dir, const HitData hit_data) {
    Material material = scene[hit_data.hittable_index].material;
    Vec3 normal = hit_data.normal;
    double relative_refraction_index;

    switch (material.type) {
        default:
        case MATTE: return get_diffuse_reflection_dir(normal); break;
        case MIRROR: return get_specular_reflection_dir(dir, normal); break;
        case CONDUCTOR: return vec3_add(vec3_normalize(get_specular_reflection_dir(dir, normal)), get_fuzzy_offset(material.fuzz));
        case DIELECTRIC:
            if (hit_data.inside_object)
                relative_refraction_index = material.refractive_index / AIR_REFRACTIVE_INDEX;
            else
                relative_refraction_index = AIR_REFRACTIVE_INDEX / material.refractive_index;
            return get_refraction_dir(vec3_normalize(dir), normal, relative_refraction_index);
        break;
    }
}
