#pragma once

#include "calc.h"

typedef struct {
    double x;
    double y;
} Vec2;

typedef struct {
    int x;
    int y;
} DVec2;

double vec2_len(const Vec2 u);
DVec2 vec2_normalize(const Vec2 u);
DVec2 dvec2_add(const DVec2 u, const DVec2 v);
DVec2 dvec2_mult_n(const DVec2 u, const double n);
Vec2 vec2_limit(const Vec2 u, const Vec2 min, const Vec2 max);
Vec2 vec2_add(const Vec2 u, const Vec2 v);
Vec2 vec2_sub(const Vec2 u, const Vec2 v);
Vec2 vec2_mult_n(const Vec2 u, const double n);
Vec2 vec2_div_n(const Vec2 u, const double n);
double vec2_dot(const Vec2 u, const Vec2 v);