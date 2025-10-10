#pragma once

#include "color_rgb.h"

#define AIR_REFRACTIVE_INDEX 1.000273
#define WATER_REFRACTIVE_INDEX 1.33
#define GLASS_REFRACTIVE_INDEX 1.52
#define DIAMOND_REFRACTIVE_INDEX 2.417

#define ENVIRONMENT_REFRACTIVE_INDEX AIR_REFRACTIVE_INDEX

typedef enum {
    MATTE,     // albedo
    MIRROR,    // ---
    CONDUCTOR, // fuzz, albedo
    DIELECTRIC // refractive index, albedo
} MaterialType;

typedef struct {
    double fuzz;
    double relative_refraction_index;
    ColorRGB albedo;
    MaterialType type;
} Material;

bool material_scatter(const MaterialType material_type, const Vec3 reflection_dir, const Vec3 normal);
bool material_add_albedo(const MaterialType material_type);
