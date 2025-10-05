#include "intersection.h"

Vec3 get_normal(const Vec3 ray, const Vec3 hittable_center) {
    Vec3 outside_normal = vec3_normalize(vec3_sub(ray, hittable_center));
    Vec3 normal = outside_normal;
    if (vec3_dot(outside_normal, ray) > 0) // if ray is inside the hittable
        normal = vec3_mult_n(outside_normal, -1);
    return normal;
}

// get a distance from (0, 0, 0) to the point
double hit_sphere(const Vec3 point, const Sphere sphere) {
    Vec3 oc = vec3_sub(sphere.center, camera_center);
    double a = vec3_dot(point, point);
    double k = vec3_dot(point, oc); // b = -2 * k
    double c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = k * k - a * c;

    if (discriminant >= 0)
        return (k - sqrt(discriminant)) / a; // the nearest hit point
    else
        return -1;
}

// get a distance from (0, 0, 0) to the point
// double hit_cube(const Vec3 point, const Cube cube) {
    
// }

// get a distance from (0, 0, 0) to the point
double hit_hittable(const Vec3 point, const Hittable hittable) {
    switch (hittable.type) {
        case SPHERE: return hit_sphere(point, hittable.data.sphere); break;
        // case CUBE: return hit_cube(point, hittable.data.cube); break;
        default: return -1; break;
    }
}

// get a hit data with the least length of a hit ray
HitData get_min_hit_data(const Vec3 point) {
    Vec3 min_hit_ray = vec3_mult_n((Vec3) {0, 0, -1}, MAX_HIT_DIST);
    int min_hittable_idx = -1;
    for (int i = 0; i < AMOUNT_OF_HITTABLES; i++) {
        Hittable hittable = scene[i];
        double hit = hit_hittable(point, hittable);
        if (hit > 0) {
            Vec3 hit_ray = get_ray(camera_center, point, hit);
            if (vec3_len(hit_ray) < vec3_len(min_hit_ray) && vec3_len(hit_ray) > MIN_HIT_DIST) {
                min_hit_ray = hit_ray;
                min_hittable_idx = i;
            }
        }
    }
    return (HitData) {min_hit_ray, min_hittable_idx};
}
