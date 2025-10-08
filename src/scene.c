#include "scene.h"

Hittable scene[] = {
    {
        .hittable_type = SPHERE,
        .material_type = MATTE,
        .sphere.center = {-0.3, 0.2, -1},
        .sphere.radius = 0.3
    },
    {
        .hittable_type = SPHERE,
        .material_type = MATTE,
        .sphere.center = {0.3, 0, -0.9},
        .sphere.radius = 0.3
    },
    {
        .hittable_type = SPHERE,
        .material_type = MATTE,
        .sphere.center = {0, -100.1, -1},
        .sphere.radius = 100
    }
};
