#include "scene.h"

Hittable scene[] = {
    {
        .type = SPHERE,
        .data.sphere.center = {0.1, 0, -1},
        .data.sphere.radius = 0.5
    },
    {
        .type = SPHERE,
        .data.sphere.center = {-0.1, 0, -1},
        .data.sphere.radius = 0.5
    },
    {
        .type = SPHERE,
        .data.sphere.center = {0, -100.5, -1},
        .data.sphere.radius = 100
    }
};
