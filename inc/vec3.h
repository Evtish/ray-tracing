#pragma once

#include "calc.h"

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char z;
} DVec3;

// typedef struct
// {
//     Vec2 i; // 1st *row*
//     Vec2 j; // 2nd *row*
// } Mat22;

double vec3_len(const Vec3 u);
DVec3 vec3_normalize(const Vec3 u);
Vec3 dvec3_mult_n(const DVec3 u, const double n);
Vec3 vec3_limit(const Vec3 u, const Vec3 min, const Vec3 max);
Vec3 vec3_add(const Vec3 u, const Vec3 v);
Vec3 vec3_sub(const Vec3 u, const Vec3 v);
Vec3 vec3_mult_n(const Vec3 u, const double n);
double vec3_dot(const Vec3 u, const Vec3 v);
// Vec3 vec2_mult_matrix(const Vec2 u, const Mat22 m);

// Mat22 mat22_mult_n(const Mat22 m, const double n);