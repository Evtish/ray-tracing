#include "ray.h"

Vec3 get_ray_end(const Ray ray, const double n) {
    return vec3_add(ray.origin, vec3_mult_n(ray.dir, n));
}
