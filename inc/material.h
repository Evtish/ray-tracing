#pragma once

#include "color_rgb.h"

#define MATTE(r, g, b) {.reflection_type = DIFFUSE, .albedo = {(r), (g), (b)}}
#define MIRROR(r, g, b) {.reflection_type = SPECULAR, .albedo = {(r), (g), (b)}}

typedef enum {
    DIFFUSE,
    SPECULAR
} MaterialReflectionType;

typedef struct {
    ColorRGB albedo;
    MaterialReflectionType reflection_type;
} Material;
