#pragma once

#include <stdio.h>

#include "ui.h"
#include "anti_aliasing.h"

#ifndef IMAGE_NAME
    #define IMAGE_NAME "image.ppm"
#endif

#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 480 // in pixels
#define IMAGE_W ((unsigned int) (IMAGE_H * ASPECT_RATIO))

void image_write_header(FILE *const image);
void image_render(FILE *const image);
