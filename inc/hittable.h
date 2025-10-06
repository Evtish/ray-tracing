#pragma once

#include "vec3.h"

typedef enum {
    SPHERE,
    // CUBE
} HittableType;

typedef struct {
    Vec3 center;
    double radius;
} Sphere;

typedef struct {
    Vec3 center;
    double a;
} Cube;

// TODO: maybe remove the union and use Sphere and Cube directly
typedef union {
    Sphere sphere;
    // Cube cube;
} HittableData;

typedef struct {
    HittableData data;
    HittableType type;
} Hittable;
