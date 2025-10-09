#pragma once

#include "calc.h"

typedef struct {
    double x;
    double y;
} Vec2;

Vec2 vec2_rand_unit_square(void);

Vec2 vec2_add(const Vec2 u, const Vec2 v);
