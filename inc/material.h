#pragma once

#include "color_rgb.h"

typedef enum {
    MATTE,
    MIRROR
} MaterialType;

typedef struct {
    ColorRGB albedo;
    MaterialType type;
} Material;

bool material_scatter(const MaterialType material_type);
Vec3 get_reflection_dir(const Vec3 dir, const Vec3 normal, const MaterialType type);
