#pragma once

#include <stdbool.h>
#include <math.h>

#include "vec3.h"
#include "viewport.h"

double hit_sphere(Vec3 center, double radius, Vec3 pixel);
