#pragma once

#include "vec3.h"
#include "material.h"

typedef enum {
    OBJ_SPHERE,
    // OBJ_CUBE
} HittableType;

typedef struct {
    Vec3 center;
    double radius;
    // double a;
} AbstractHittable;

typedef struct {
    Vec3 center;
    double radius;
} Sphere;

// typedef struct {
//     Vec3 center;
//     double a;
// } Cube;

typedef union {
    AbstractHittable abstract;
    Sphere sphere;
    // Cube cube;
} HittableObj;

typedef struct {
    HittableObj obj;
    Material material;
    HittableType type;
} Hittable;

typedef struct {
    Vec3 hit_point;
    Vec3 normal;
    int hittable_index;
    bool inside_object;
} HitData;
