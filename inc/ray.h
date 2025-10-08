#pragma once

#include "vec2.h"
#include "vec3.h"

typedef struct {
    Vec3 origin;
    Vec3 dir;
} Ray;

Vec3 get_ray_end(const Ray ray, const double n);
