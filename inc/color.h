#pragma once

#include "viewport.h"
#include "intersection.h"
#include "color_rgb.h"
#include "scene.h"

ColorRGB get_point_color(const Ray ray, const int amount_of_reflections);
void color_correct_gamma(ColorRGB *p_color);
