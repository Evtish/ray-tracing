#include "scene.h"

Hittable scene[] = {
    // ground
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, -100.5, -1},
            .radius = 100
        },
        .material = {
            .type = MATTE,
            .albedo = {170, 255, 0}
        }
    },

    // left (outer glass)
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-1, 0, -1},
            .radius = 0.5
        },
        .material = {
            .type = DIELECTRIC,
            .relative_refraction_index = GLASS_REFRACTIVE_INDEX / ENVIRONMENT_REFRACTIVE_INDEX
        }
    },

    // left (inner air)
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-1, 0, -1},
            .radius = 0.4
        },
        .material = {
            .type = DIELECTRIC,
            .relative_refraction_index = AIR_REFRACTIVE_INDEX / GLASS_REFRACTIVE_INDEX
        }
    },

    // center
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, 0, -1.2},
            .radius = 0.5
        },
        .material = {
            .type = MATTE,
            .albedo = {26, 51, 128}
        },
    },

    // right
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {1, 0, -1},
            .radius = 0.5
        },
        .material = {
            .type = CONDUCTOR,
            .albedo = {170, 255, 170},
            .fuzz = 1
        },
    }
};
