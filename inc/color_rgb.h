#pragma once

#include "vec3.h"

#define START_COLOR_VAL 0
#define MAX_COLOR_VAL 255

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ColorRGB;

ColorRGB color_mult_color(const ColorRGB u, const ColorRGB v);
ColorRGB color_mult_n(const ColorRGB u, const double n);
ColorRGB color_blend(const ColorRGB a, const ColorRGB b, const double k);
