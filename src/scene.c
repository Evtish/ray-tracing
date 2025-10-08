#include "scene.h"

Hittable scene[] = {
    {
        .material = MATTE(204, 204, 0),
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, -100.5, -1},
            .radius = 100
        }
    },
    {
        .material = MIRROR(204, 204, 204),
        .hittable_type = SPHERE,
        .sphere = {
            .center = {-1, 0, -1},
            .radius = 0.5
        }
    },
    {
        .material = MATTE(26, 51, 128),
        .hittable_type = SPHERE,
        .sphere = {
            .center = {0, 0, -1.2},
            .radius = 0.5
        }
    },
    {
        .material = MIRROR(204, 153, 51),
        .hittable_type = SPHERE,
        .sphere = {
            .center = {1, 0, -1},
            .radius = 0.5
        }
    }
};
