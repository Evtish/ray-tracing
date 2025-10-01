#pragma once

#include <stdbool.h>

#include "vec3.h"
#include "viewport.h"

bool hit_sphere(Vec3 center, double radius, Vec3 pixel);