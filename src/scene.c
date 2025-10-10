#include "scene.h"

Hittable scene[] = {
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
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-1, 0, -1},
            .radius = 0.5
        },
        .material = {
            .type = DIELECTRIC,
            .refractive_index = AIR_REFRACTIVE_INDEX
        }
    },
    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, -0.5, -1.2},
            .radius = 0.5
        },
        .material = {
            .type = MATTE,
            .albedo = {26, 51, 128}
        },
    },
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
