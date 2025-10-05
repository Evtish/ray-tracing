#pragma once

#include "vec3.h"
#include "viewport.h"
#include "intersection.h"
#include "scene.h"

#define START_COLOR_VAL 0
#define MAX_COLOR_VAL 255

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ColorRGB;

ColorRGB get_point_color(const Vec3 point);
