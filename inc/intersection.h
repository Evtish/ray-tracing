#pragma once

#include <stdbool.h>
#include <math.h>

#include "vec3.h"
#include "viewport.h"
#include "hitable.h"
#include "scene.h"

#define MIN_HIT_DIST 0.01
#define MAX_HIT_DIST 1000

typedef struct {
    Vec3 hit_ray;
    int hittable_index;
} HitData;

Vec3 get_ray(const Vec3 start, const Vec3 dir, const double n);
Vec3 get_normal(const Vec3 ray, const Vec3 hittable_center);

// double hit_sphere(const Vec3 point, const Sphere sphere);
// double hit_cube(const Vec3 point, const Cube cube);
// double hit_hittable(const Vec3 point, const Hittable hittable);

HitData get_min_hit_data(const Vec3 point);