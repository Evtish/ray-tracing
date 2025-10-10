#pragma once

#include "hittable.h"
#include "scene.h"
#include "point_color.h"

Vec3 reflefraction_get_dir(const Vec3 dir, const HitData *const hit_data);
