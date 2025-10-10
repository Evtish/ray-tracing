#pragma once

#include "color_rgb.h"

#define AIR_REFRACTIVE_INDEX 1.000273
#define GLASS_REFRACTIVE_INDEX 1.52

typedef enum {
    MATTE,     // albedo
    MIRROR,    // ---
    CONDUCTOR, // fuzz, albedo
    DIELECTRIC // refractive index, albedo
} MaterialType;

typedef struct {
    double fuzz;
    double refractive_index;
    ColorRGB albedo;
    MaterialType type;
} Material;

bool material_scatter(const MaterialType material_type, const Vec3 reflection_dir, const Vec3 normal);
bool material_add_albedo(const MaterialType material_type);
