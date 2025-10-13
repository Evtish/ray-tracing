#include "material.h"

bool material_scatter(const MaterialType material_type, const Vec3 reflection_dir, const Vec3 normal) {
    switch (material_type) {
        default:
        case MAT_MATTE:
        case MAT_MIRROR:
        case MAT_DIELECTRIC: return true; break;
        
        case MAT_CONDUCTOR: return (vec3_dot(reflection_dir, normal) > 0); break; // the ray is absorbed if it is pointing into the object
    }
}

bool material_add_albedo(const MaterialType material_type) {
    switch (material_type) {
        default:
        case MAT_MIRROR:
        case MAT_DIELECTRIC: return false; break;

        case MAT_MATTE:
        case MAT_CONDUCTOR: return true; break;
    }
}
