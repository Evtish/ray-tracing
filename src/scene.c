#include "scene.h"

Figure scene[] = {
    {
        .type = SPHERE,
        .data.sphere = (Sphere) {
            (Vec3) {0, 0, -1},
            0.5
        }
    },
    {
        .type = SPHERE,
        .data.sphere = (Sphere) {
            (Vec3) {-0.1, 0.5, -1.5},
            0.5
        }
    }
};
