#include "ray.h"

Vec3 get_ray(Vec3 start, Vec3 dir, double n) {
    return vec3_add(start, vec3_mult_n(dir, n));
}