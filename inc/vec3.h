#pragma once

#include "calc.h"

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

double vec3_len(const Vec3 u);
double vec3_dot(const Vec3 u, const Vec3 v);

Vec3 vec3_normalize(const Vec3 u);
Vec3 vec3_rand_unit(void);
Vec3 vec3_rand_unit_hemisphere(const Vec3 normal);

Vec3 vec3_add(const Vec3 u, const Vec3 v);
Vec3 vec3_sub(const Vec3 u, const Vec3 v);
Vec3 vec3_mult_n(const Vec3 u, const double n);
Vec3 vec3_div_n(const Vec3 u, const double n);

bool vec3_near_zero(const Vec3 u);
