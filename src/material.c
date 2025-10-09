#include "material.h"

bool material_scatter(const MaterialType material_type, const Vec3 reflection_dir, const Vec3 normal) {
    switch (material_type) {
        default:
        case MATTE:
        case MIRROR: return true; break;
        case METAL: return (vec3_dot(reflection_dir, normal) > 0); break;
    }
}

Vec3 get_diffuse_reflection_dir(const Vec3 normal) {
    Vec3 reflected_dir;
    do {
        reflected_dir = vec3_add(normal, vec3_rand_unit());
    } while (vec3_near_zero(reflected_dir));
    return reflected_dir;
}

Vec3 get_specular_reflection_dir(const Vec3 dir, const Vec3 normal) {
    // reflected_dir = dir - 2 * dot(normal, dir) * normal
    return vec3_sub(dir, vec3_mult_n(normal, 2 * vec3_dot(normal, dir)));
}

Vec3 get_fuzzy_offset_dir(const double fuzz) {
    return vec3_mult_n(vec3_rand_unit(), fuzz);
} 

Vec3 get_reflection_dir(const Vec3 dir, const Vec3 normal, const Material material) {
    switch (material.type) {
        default:
        case MATTE: return get_diffuse_reflection_dir(normal); break;
        case MIRROR: return get_specular_reflection_dir(dir, normal); break;
        case METAL: return vec3_add(vec3_normalize(get_specular_reflection_dir(dir, normal)), get_fuzzy_offset_dir(material.fuzz));
    }
}
