#pragma once

#include <stdbool.h>
#include <math.h>

#include "vec3.h"
#include "viewport.h"
#include "hitable.h"

double hit_sphere(const Vec3 pixel, const Sphere sphere);
double hit_cube(const Vec3 pixel, const Cube cube);
double hit_figure(const Vec3 pixel, const Figure figure);
