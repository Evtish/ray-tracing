#include "ray.h"

Vec3 get_ray(const Vec3 start, const Vec3 dir, const double n) {
    return vec3_add(start, vec3_mult_n(dir, n));
}
