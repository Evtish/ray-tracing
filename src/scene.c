#include "scene.h"

Hittable scene[] = {
    {
        .hittable_type = SPHERE,
        .material_type = MATTE,
        .sphere.center = {0, 0, -1},
        .sphere.radius = 0.5
    },
    // {
    //     .hittable_type = SPHERE,
    //     .material_type = MATTE,
    //     .sphere.center = {0.3, 0, -0.9},
    //     .sphere.radius = 0.5
    // },
    {
        .hittable_type = SPHERE,
        .material_type = MATTE,
        .sphere.center = {0, -100.5, -1},
        .sphere.radius = 100
    }
};
