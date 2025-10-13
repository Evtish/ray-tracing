#include "scene.h"

Hittable scene[] = {
    // ground
    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {0, -100.5, -1},
            .radius = 100
        },
        .material = {
            .type = MAT_MATTE,
            .albedo = {255, 170, 255}
        }
    },

    // left (outer glass)
    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {-1, 0, -1},
            .radius = 0.5
        },
        .material = {
            .type = MAT_DIELECTRIC,
            .relative_refraction_index = GLASS_REFRACTIVE_INDEX / ENVIRONMENT_REFRACTIVE_INDEX
        }
    },

    // left (inner air)
    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {-1, 0, -1},
            .radius = 0.4
        },
        .material = {
            .type = MAT_DIELECTRIC,
            .relative_refraction_index = AIR_REFRACTIVE_INDEX / GLASS_REFRACTIVE_INDEX
        }
    },

    // center
    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {0, 0, -1.2},
            .radius = 0.5
        },
        .material = {
            .type = MAT_MATTE,
            .albedo = {128, 26, 51}
        },
    },

    // right
    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {1, 0, -1},
            .radius = 0.5
        },
        .material = {
            .type = MAT_CONDUCTOR,
            .albedo = {170, 255, 170},
            .fuzz = 0.8
        },
    },

    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {0.6, 0.3, -0.8},
            .radius = 0.15
        },
        .material = {
            .type = MAT_CONDUCTOR,
            .albedo = {255, 170, 0},
            .fuzz = 0.6
        },
    },

    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {-0.5, 0.6, -1},
            .radius = 0.2
        },
        .material = {
            .type = MAT_MIRROR
        },
    },

    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {-1, 0, -1.5},
            .radius = 0.5
        },
        .material = {
            .type = MAT_CONDUCTOR,
            .albedo = {0, 190, 130},
            .fuzz = 0
        },
    },

    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {0, -0.3, -0.5},
            .radius = 0.1
        },
        .material = {
            .type = MAT_MIRROR
        },
    },

    {
        .type = OBJ_SPHERE,
        .obj.abstract = {
            .center = {0.201, -0.3, -0.5},
            .radius = 0.1
        },
        .material = {
            .type = MAT_MIRROR
        },
    }
};
