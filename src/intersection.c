#include "intersection.h"

double hit_sphere(const Vec3 pixel, const Sphere sphere) {
    Vec3 oc = vec3_sub(sphere.center, camera_center);
    double a = vec3_dot(pixel, pixel);
    double k = vec3_dot(pixel, oc); // b = -2 * k
    double c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = k * k - a * c;

    if (discriminant >= 0)
        return (k + sqrt(discriminant)) / a;
    else
        return -1;
}

double hit_cube(const Vec3 pixel, const Cube cube) {

}

double hit_figure(const Vec3 pixel, const Figure figure) {
    switch (figure.type) {
        case SPHERE: return hit_sphere(pixel, figure.data.sphere); break;
        case CUBE: return hit_cube(pixel, figure.data.cube); break;
    }
}
