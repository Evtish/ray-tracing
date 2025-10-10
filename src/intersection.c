#include "intersection.h"

// void fix_fisheye(double *hit, const Ray ray, const Vec3 normal) {
//     Vec3 normalized_ray_end = vec3_normalize(get_ray_end(ray, 1));
//     *hit *= vec3_dot(normalized_ray_end, normal);
// }

bool get_hittable_normal(Vec3 *const p_normal, const int hittable_index, const Vec3 hit_point, const Vec3 ray_dir) {
    Hittable hittable = scene[hittable_index];
    Vec3 hittable_center;
    switch (hittable.hittable_type) {
        case SPHERE:
            hittable_center = hittable.sphere.center;
        // default: return (Vec3) {0, 0, 0};
    }

    Vec3 outside_normal = vec3_normalize(vec3_sub(hit_point, hittable_center));
    if (vec3_dot(outside_normal, ray_dir) > 0) { // if the end of the ray is inside the hittable
        *p_normal = vec3_mult_n(outside_normal, -1);
        return true;
    }
    *p_normal = outside_normal;
    return false;
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

// get n to the point
// double hit_cube(const Vec3 point, const Cube cube) {
    
// }

// get n to the point
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

    if (min_hittable_idx >= 0) {
        Vec3 real_hit_point = get_ray_end(ray, min_hit), normal;
        bool inside_object = get_hittable_normal(&normal, min_hittable_idx, real_hit_point, ray.dir);
        // Vec3 normal = get_hittable_normal((HitData) {real_hit_point, min_hittable_idx});
        // fix_fisheye(&min_hit, ray, normal);
        
        // Vec3 fixed_hit_point = get_ray_end(ray, min_hit);
        return (HitData) {
            .hit_point = real_hit_point,
            .hittable_index = min_hittable_idx,
            .normal = normal,
            .inside_object = inside_object
        };
    }
    return (HitData) {.hittable_index = min_hittable_idx};
}
