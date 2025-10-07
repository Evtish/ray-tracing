#include "intersection.h"

Vec3 get_normal(const Vec3 ray_end, const Vec3 hittable_center) {
    Vec3 outside_normal = vec3_normalize(vec3_sub(ray_end, hittable_center));
    Vec3 normal = outside_normal;
    if (vec3_dot(outside_normal, ray_end) > 0) // if the end of the ray is inside the hittable
        normal = vec3_mult_n(outside_normal, -1);
    return normal;
}

// get a distance from (0, 0, 0) to the point
double hit_sphere(const Ray ray, const Sphere sphere) {
    Vec3 oc = vec3_sub(sphere.center, ray.start);
    double a = vec3_dot(ray.end, ray.end);
    double k = vec3_dot(ray.end, oc); // b = -2 * k
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
double hit_hittable(const Ray ray, const Hittable hittable) {
    switch (hittable.hittable_type) {
        case SPHERE: return hit_sphere(ray, hittable.sphere); break;
        // case CUBE: return hit_cube(point, hittable.data.cube); break;
        default: return -1; break;
    }
}

// get a hit data with the least length of a hit ray
HitData get_min_hit_data(const Ray ray) {
    double min_hit_ray_len = MAX_HIT_DIST;
    int min_hittable_idx = -1;
    for (int i = 0; i < AMOUNT_OF_HITTABLES; i++) {
        Hittable hittable = scene[i];
        double hit = hit_hittable(ray, hittable);
        if (hit > 0) { // if there is a hit
            Vec3 hit_ray_end = get_ray_end(ray.start, vec3_sub(ray.end, ray.start), hit);
            double hit_ray_len = vec3_len(hit_ray_end);
            if (finterval_surrounds(hit_ray_len, MIN_HIT_DIST, min_hit_ray_len)) {
                min_hit_ray_len = hit_ray_len;
                min_hittable_idx = i;
            }
        }
    }

    // Vec3 min_hit_ray_end = get_ray_end(ray.start, vec3_sub(ray.end, ray.start), min_hit_ray_len);
    Ray min_hit_ray = {ray.start, vec3_mult_n(ray.end, min_hit_ray_len / vec3_len(ray.end))};
    return (HitData) {min_hit_ray, min_hittable_idx};
}
