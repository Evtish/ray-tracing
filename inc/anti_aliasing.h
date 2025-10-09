#pragma once

#include "calc.h"
#include "vec2.h"
#include "vec3.h"
#include "color_rgb.h"
#include "viewport.h"
#include "point_color.h"

ColorRGB get_anti_aliased_pixel_color(const Vec2 pixel, const int amount_of_reflections);