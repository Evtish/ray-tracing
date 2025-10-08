#pragma once

#include <float.h>

#include "calc.h"
#include "vec3.h"
#include "ray.h"
#include "viewport.h"
#include "hittable.h"
#include "scene.h"

#define MIN_HIT 1e-2
#define MAX_HIT DBL_MAX

typedef struct {
    Vec3 hit_point;
    int hittable_index;
} HitData;

Vec3 get_hittable_normal(const HitData hit_data, const Vec3 ray_dir);
HitData get_min_hit_data(const Ray ray);
