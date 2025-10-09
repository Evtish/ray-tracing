#include "point_color.h"

#define REFLECTED_RAY_OFFSET 1e-5

#define COLOR_BLACK ((ColorRGB) {0, 0, 0})
#define GRADIENT_COLOR_A ((ColorRGB) {128, 179, 255})
#define GRADIENT_COLOR_B ((ColorRGB) {255, 255, 255})

typedef enum {
    VERTICAL,
    HORIZONTAL
} GradientType;

ColorRGB background_gradient(const Vec3 ray_dir, const GradientType gradient_type) {
    double blend_k = 0;
    switch (gradient_type) {
        case VERTICAL: blend_k = fmap(ray_dir.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, 0, 1); break;
        case HORIZONTAL: blend_k = fmap(ray_dir.x, -VIEWPORT_W / 2, VIEWPORT_W / 2, 0, 1); break;
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
        Vec3 normal = get_hittable_normal(hit_data, ray.dir);
        Vec3 reflected_ray_origin = vec3_add(hit_data.hit_point, vec3_mult_n(normal, REFLECTED_RAY_OFFSET)); // raise the point slightly above the surface to avoid floating point errors
        Vec3 reflected_ray_dir = get_reflection_dir(ray.dir, normal, material);
    
        if (!material_scatter(material.type, reflected_ray_dir, normal)) // if ray is absorbed into the material
            return COLOR_BLACK;

        Ray reflected_ray = {reflected_ray_origin, reflected_ray_dir};
        return color_mult_color(get_point_color(reflected_ray, amount_of_reflections - 1), material.albedo);
    }

    else return background_gradient(ray.dir, VERTICAL);
}
