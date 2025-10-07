#pragma once

#include "calc.h"
#include "vec3.h"
#include "ray.h"
#include "viewport.h"
#include "hittable.h"
#include "scene.h"

#define MIN_HIT_DIST 1e-6
#define MAX_HIT_DIST 1e100

typedef struct {
    Ray hit_ray;
    int hittable_index;
} HitData;

Vec3 get_hittable_normal(const HitData hit_data);
HitData get_min_hit_data(const Ray ray);
