#include "intersection.h"

bool get_hittable_normal(Vec3 *const p_normal, const int hittable_index, const Vec3 hit_point, const Vec3 ray_dir) {
    Hittable *hittable = &scene[hittable_index];
    Vec3 hittable_center = hittable->obj.abstract.center;

    Vec3 outside_normal = vec3_normalize(vec3_sub(hit_point, hittable_center));
    bool inside_object = (vec3_dot(outside_normal, ray_dir) > 0);

    *p_normal = inside_object ? vec3_mult_n(outside_normal, -1) : outside_normal;
    return inside_object;
}

// A²t² - 2At(O-C) + (O-C)² - r² = 0
double hit_sphere(const Ray ray, const Sphere *const sphere) {
    Vec3 oc = vec3_sub(sphere->center, ray.origin);
    double a = vec3_squared_len(ray.dir);
    double k = vec3_dot(ray.dir, oc); // b = -2 * k
    double c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
    double discriminant = k * k - a * c;

    if (discriminant >= 0) {
        double squared_discriminant = sqrt(discriminant);
        double root = (k - squared_discriminant) / a;
        if (!finterval_contains(root, MIN_HIT, MAX_HIT)) {
            root = (k + squared_discriminant) / a;
            if (!finterval_contains(root, MIN_HIT, MAX_HIT))
                return -1;
        }
        return root; // the nearest hit point within the hit interval
    }
    else
        return -1;
}

// get n to the point
// double hit_cube(const Vec3 point, const Cube cube) {
    
// }

// get a distation to the point in a ray steps
double hit_hittable(const Ray ray, const Hittable *const hittable) {
    switch (hittable->type) {
        case OBJ_SPHERE: return hit_sphere(ray, &(hittable->obj.sphere)); break;
        // case OBJ_CUBE: return hit_cube(point, hittable->obj.cube); break;
        default: return -1; break;
    }
}

// get a hit data with the least length of a hit ray
HitData get_min_hit_data(const Ray ray) {
    double min_hit = MAX_HIT;
    int min_hittable_idx = -1;
    for (int i = 0; i < AMOUNT_OF_HITTABLES; i++) {
        double hit = hit_hittable(ray, &scene[i]);
        if (hit > 0 && hit < min_hit) {
            min_hit = hit;
            min_hittable_idx = i;
        }
    }

    if (min_hittable_idx >= 0) {
        Vec3 real_hit_point = get_ray_end(ray, min_hit), normal;
        bool inside_object = get_hittable_normal(&normal, min_hittable_idx, real_hit_point, ray.dir);

        return (HitData) {
            .hit_point = real_hit_point,
            .hittable_index = min_hittable_idx,
            .normal = normal,
            .inside_object = inside_object
        };
    }
    return (HitData) {.hittable_index = min_hittable_idx};
}
