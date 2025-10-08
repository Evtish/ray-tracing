#include "intersection.h"

Vec3 get_hittable_normal(const HitData hit_data) {
    Hittable hittable = scene[hit_data.hittable_index];
    Vec3 hittable_center;
    switch (hittable.hittable_type) {
        case SPHERE:
            hittable_center = hittable.sphere.center;
        // default: return (Vec3) {0, 0, 0};
    }

    Vec3 outside_normal = vec3_normalize(vec3_sub(hit_data.hit_point, hittable_center));
    Vec3 normal = outside_normal;
    if (vec3_dot(outside_normal, hit_data.hit_point) > 0) // if the end of the ray is inside the hittable
        normal = vec3_mult_n(outside_normal, -1);
    return normal;
}

// A²t² - 2At(O-C) + (O-C)² - r² = 0
double hit_sphere(const Ray ray, const Sphere sphere) {
    Vec3 oc = vec3_sub(sphere.center, ray.origin);
    double a = vec3_dot(ray.dir, ray.dir);
    double k = vec3_dot(ray.dir, oc); // b = -2 * k
    double c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = k * k - a * c;

    if (discriminant >= 0) {
        double squared_discriminant = sqrt(discriminant);
        double root = (k - squared_discriminant) / a;
        if (!finterval_contains(root, MIN_HIT, MAX_HIT)) {
            root = (k + squared_discriminant) / a;
            if (!finterval_contains(root, MIN_HIT, MAX_HIT))
                return -1;
        }
        return root; // the nearest hit point
    }
    else
        return -1;
}

// get a distance from (0, 0, 0) to the point
// double hit_cube(const Vec3 point, const Cube cube) {
    
// }

// get a distance from (0, 0, 0) to the point
double hit_hittable(const Ray ray, const Hittable hittable) {
    switch (hittable.hittable_type) {
        case SPHERE: return hit_sphere(ray, hittable.sphere); break;
        // case CUBE: return hit_cube(point, hittable.data.cube); break;
        default: return -1; break;
    }
}

// get a hit data with the least length of a hit ray
HitData get_min_hit_data(const Ray ray) {
    double min_hit = MAX_HIT;
    int min_hittable_idx = -1;
    for (int i = 0; i < AMOUNT_OF_HITTABLES; i++) {
        double hit = hit_hittable(ray, scene[i]);
        if (hit > 0 && hit < min_hit) { // if there is a hit that less than the previous one
            min_hit = hit;
            min_hittable_idx = i;
        }
    }
    // Vec3 min_hit_ray_end = get_ray_end(ray.origin, vec3_sub(ray.end, ray.origin), min_hit);
    Vec3 hit_point = get_ray_end(ray, min_hit);
    return (HitData) {hit_point, min_hittable_idx};
}
