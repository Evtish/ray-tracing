#pragma once

#include <float.h>

#include "calc.h"
#include "vec3.h"
#include "ray.h"
#include "viewport.h"
#include "hittable.h"
#include "scene.h"

#define MIN_HIT 1e-3
#define MAX_HIT DBL_MAX

HitData get_min_hit_data(const Ray ray);
