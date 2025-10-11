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
            .albedo = {255, 170, 255}
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
            .albedo = {128, 26, 51}
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
            .fuzz = 0.8
        },
    },

    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0.6, 0.3, -0.8},
            .radius = 0.15
        },
        .material = {
            .type = CONDUCTOR,
            .albedo = {255, 170, 0},
            .fuzz = 0.6
        },
    },

    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-0.5, 0.6, -1},
            .radius = 0.2
        },
        .material = {
            .type = MIRROR
        },
    },

    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-1, 0, -1.5},
            .radius = 0.5
        },
        .material = {
            .type = CONDUCTOR,
            .albedo = {0, 190, 130},
            .fuzz = 0
        },
    },

    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, -0.3, -0.5},
            .radius = 0.1
        },
        .material = {
            .type = MIRROR
        },
    },

    {
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0.201, -0.3, -0.5},
            .radius = 0.1
        },
        .material = {
            .type = MIRROR
        },
    }
};
