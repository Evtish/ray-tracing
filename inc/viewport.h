#pragma once

// #include "vec2.h"
#include "vec3.h"
#include "image.h"

#define VIEWPORT_H 2.0
#define VIEWPORT_W (VIEWPORT_H * IMAGE_W / IMAGE_H)
#define FOCAL_LENGTH 1.0

extern Vec3 camera_center;