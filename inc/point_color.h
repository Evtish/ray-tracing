#pragma once

#include "viewport.h"
#include "ray.h"
#include "intersection.h"
#include "reflefraction.h"

ColorRGB get_point_color(const Ray ray, const int amount_of_reflections);
