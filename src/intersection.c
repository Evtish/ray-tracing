#include "intersection.h"

double hit_sphere(Vec3 center, double radius, Vec3 pixel) {
    Vec3 oc = vec3_sub(center, camera_center);
    double a = vec3_dot(pixel, pixel);
    double b = -2 * vec3_dot(pixel, oc);
    double c = vec3_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0)
        return (-b - sqrt(discriminant)) / (2 * a);
    else
        return -1;
}
