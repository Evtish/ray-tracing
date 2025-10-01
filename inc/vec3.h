#pragma once

#include "calc.h"

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    int x;
    int y;
    int z;
} DVec3;

double vec3_len(const Vec3 u);
DVec3 vec3_normalize(const Vec3 u);
DVec3 dvec3_add(const DVec3 u, const DVec3 v);
DVec3 dvec3_mult_n(const DVec3 u, const double n);
Vec3 vec3_limit(const Vec3 u, const Vec3 min, const Vec3 max);
Vec3 vec3_add(const Vec3 u, const Vec3 v);
Vec3 vec3_sub(const Vec3 u, const Vec3 v);
Vec3 vec3_mult_n(const Vec3 u, const double n);
Vec3 vec3_div_n(const Vec3 u, const double n);
double vec3_dot(const Vec3 u, const Vec3 v);