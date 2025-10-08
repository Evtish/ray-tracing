#include "color.h"

#define REFLECTED_COLOR_LOSS_K 0.7

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

ColorRGB fcolor_gradient(
    const double val,
    const double min_val,
    const double max_val,
    const ColorRGB a,
    const ColorRGB b
) {
    double blend_k = fmap(val, min_val, max_val, 0, 1);
    return color_add(
        color_mult_n(a, 1 - blend_k),
        color_mult_n(b, blend_k)
    ); // a * (1 - blend_k) + b * blend_k
}

ColorRGB get_point_color(const Ray ray, const int amount_of_reflections) {
    if (amount_of_reflections < 0)
        return (ColorRGB) {0, 0, 0};

    HitData hit_data = get_min_hit_data(ray);
    if (hit_data.hittable_index >= 0) {
        Vec3 normal = get_hittable_normal(hit_data),
        reflected_ray_origin = hit_data.hit_point,
        reflected_ray_dir = vec3_add(normal, vec3_rand_unit());
        Ray reflected_ray = {reflected_ray_origin, reflected_ray_dir};
        return color_mult_n(get_point_color(reflected_ray, amount_of_reflections - 1), REFLECTED_COLOR_LOSS_K);
    }
    else {
        ColorRGB color_a = {255, 255, 255}, color_b = {127, 179, 255}; // a - bottom of the image, b - top
        return fcolor_gradient(ray.dir.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, color_a, color_b);
    }
}
