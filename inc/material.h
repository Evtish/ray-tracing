#pragma once

#include "color_rgb.h"

typedef enum {
    MATTE,
    MIRROR,
    METAL
} MaterialType;

typedef struct {
    double fuzz;
    ColorRGB albedo;
    MaterialType type;
} Material;

bool material_scatter(const MaterialType material_type, const Vec3 reflection_dir, const Vec3 normal);
Vec3 get_reflection_dir(const Vec3 dir, const Vec3 normal, const Material material);
