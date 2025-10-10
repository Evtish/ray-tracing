#pragma once

#include "vec3.h"
#include "material.h"

typedef enum {
    SPHERE,
    // CUBE
} HittableType;

typedef struct {
    Vec3 center;
    double radius;
} Sphere;

// typedef struct {
//     Vec3 center;
//     double a;
// } Cube;

// TODO: maybe remove the union and use Sphere and Cube directly
// typedef union {
//     Sphere sphere;
//     // Cube cube;
// } HittableData;

typedef struct {
    Sphere sphere;
    // Cube cube;
    Material material;
    HittableType hittable_type;
} Hittable;

typedef struct {
    Vec3 hit_point;
    Vec3 normal;
    int hittable_index;
    bool inside_object;
} HitData;
