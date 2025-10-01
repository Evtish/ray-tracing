#pragma once

#include <stdio.h>
#include <math.h>

#include "vec3.h"
// #include "viewport.h"

#define START_COLOR_VAL 0
#define MAX_COLOR_VAL 255

typedef DVec3 ColorRGB;

ColorRGB get_pixel_color_circle(const Vec3 pixel, const Vec3 circle_center);