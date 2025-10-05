#include "intersection.h"

double hit_sphere(Vec3 center, double radius, Vec3 pixel) {
    Vec3 oc = vec3_sub(center, camera_center);
    double a = vec3_dot(pixel, pixel);
    double k = vec3_dot(pixel, oc); // b = -2 * k
    double c = vec3_dot(oc, oc) - radius * radius;
    double discriminant = k * k - a * c;

    if (discriminant >= 0)
        return (k + sqrt(discriminant)) / a;
    else
        return -1;
}
