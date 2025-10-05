#pragma once

#include "calc.h"
#include "vec3.h"
#include "ray.h"
#include "viewport.h"
#include "hitable.h"
#include "scene.h"

#define MIN_HIT_DIST 0.01
#define MAX_HIT_DIST 1000

typedef struct {
    Vec3 hit_ray;
    int hittable_index;
} HitData;

Vec3 get_normal(const Vec3 ray, const Vec3 hittable_center);
HitData get_min_hit_data(const Vec3 point);
