#pragma once

#include <stdio.h>

#include "vec2.h"
#include "vec3.h"
#include "viewport.h"
#include "ui.h"
#include "point_color.h"

#ifndef IMAGE_NAME
    #define IMAGE_NAME "image.ppm"
#endif

#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 360
#define IMAGE_W ((unsigned int) (IMAGE_H * ASPECT_RATIO))

void image_write_header(FILE *const image);
void image_render(FILE *const image);
