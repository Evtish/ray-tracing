#include "point_color.h"

#define REFLECTED_RAY_OFFSET 1e-5

#define COLOR_BLACK ((ColorRGB) {0, 0, 0})
#define GRADIENT_COLOR_A ((ColorRGB) {0, 70, 255})
#define GRADIENT_COLOR_B ((ColorRGB) {255, 255, 255})

typedef enum {
    GRAD_VERTICAL,
    GRAD_HORIZONTAL
} GradientType;

ColorRGB background_gradient(const Vec3 ray_dir, const GradientType gradient_type) {
    double blend_k = 0;
    switch (gradient_type) {
        default:
        case GRAD_VERTICAL: blend_k = fmap(ray_dir.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, 0, 1); break;
        case GRAD_HORIZONTAL: blend_k = fmap(ray_dir.x, -VIEWPORT_W / 2, VIEWPORT_W / 2, 0, 1); break;
    }
    return color_blend(GRADIENT_COLOR_A, GRADIENT_COLOR_B, blend_k);
}

ColorRGB get_point_color(const Ray ray, const int amount_of_reflections) {
    if (amount_of_reflections < 0)
        return COLOR_BLACK;

    HitData hit_data = get_min_hit_data(ray);
    int hittable_idx = hit_data.hittable_index;

    if (hittable_idx >= 0) {
        Material material = scene[hittable_idx].material;
        Vec3 reflefracted_ray_dir = reflefraction_get_dir(ray.dir, &hit_data);
        if (!material_scatter(material.type, reflefracted_ray_dir, hit_data.normal)) // if the ray is absorbed into the material
            return COLOR_BLACK;

        Vec3 reflefracted_ray_origin = vec3_add(hit_data.hit_point, vec3_mult_n(hit_data.normal, REFLECTED_RAY_OFFSET)); // raise the point slightly above the surface to avoid floating point errors
        Ray reflefracted_ray = {reflefracted_ray_origin, reflefracted_ray_dir};

        ColorRGB clean_new_color = get_point_color(reflefracted_ray, amount_of_reflections - 1);
        if (material_add_albedo(material.type))
            return color_mult_color(clean_new_color, material.albedo);
        return clean_new_color;
    }

    else return background_gradient(ray.dir, GRAD_VERTICAL);
}
