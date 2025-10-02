#pragma once

#ifndef IMAGE_NAME
    #define IMAGE_NAME "image.ppm"
#endif

#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 1080U
#define IMAGE_W ((unsigned int) (IMAGE_H * ASPECT_RATIO))