#pragma once

#include "calc.h"
#include "vec3.h"
#include "ray.h"
#include "viewport.h"
#include "hittable.h"
#include "scene.h"

#define MIN_HIT_DIST 0.01
#define MAX_HIT_DIST 1000

typedef struct {
    Ray hit_ray;
    int hittable_index;
} HitData;

Vec3 get_normal(const Vec3 ray_end, const Vec3 hittable_center);
HitData get_min_hit_data(const Ray ray);
