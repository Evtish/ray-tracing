#include "intersection.h"

bool hit_sphere(Vec3 center, double radius, Vec3 pixel) {
    Vec3 oc = vec3_sub(center, camera_center);
    double a = vec3_dot(pixel, pixel);
    double b = -2 * vec3_dot(pixel, oc);
    double c = vec3_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    return discriminant >= 0;
}