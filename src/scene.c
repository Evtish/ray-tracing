#include "scene.h"

Hittable scene[] = {
    {
        .type = SPHERE,
        .data.sphere.center = {0, 0, -1},
        .data.sphere.radius = 0.5
    },
    {
        .type = SPHERE,
        .data.sphere.center = {0.3, 0, -0.9},
        .data.sphere.radius = 0.5
    },
    {
        .type = SPHERE,
        .data.sphere.center = {0, -100.5, -1},
        .data.sphere.radius = 100
    }
};
