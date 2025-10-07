#pragma once

#include "vec2.h"
#include "vec3.h"

typedef struct {
    Vec3 start;
    Vec3 end;
} Ray;

Vec3 get_ray_end(const Vec3 start, const Vec3 dir, const double n);
