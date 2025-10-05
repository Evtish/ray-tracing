#pragma once

#include "vec3.h"

typedef enum {
    SPHERE,
    CUBE
} FigureType;

typedef struct {
    Vec3 center;
    double radius;
} Sphere;

typedef struct {
    Vec3 center;
    double a;
} Cube;

typedef union {
    Sphere sphere;
    Cube cube;
} FigureData;

typedef struct {
    FigureData data;
    FigureType type;
} Figure;