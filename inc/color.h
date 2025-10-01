#pragma once

#include <stdio.h>
#include <math.h>

#include "vec3.h"
// #include "ppm.h"
#include "viewport.h"
#include "intersection.h"

#define START_COLOR_VAL 0
#define MAX_COLOR_VAL 255

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ColorRGB;

// ColorRGB get_pixel_color_circle(const Vec3 pixel, const Vec3 circle_center);
ColorRGB get_pixel_color(const Vec3 pixel);