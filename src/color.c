#include "color.h"

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

// bool get_hittable_color(const Ray ray, ColorRGB *p_color) {
//     // static bool was_hit = false;
//     static int amount_of_reflections = 0;

//     HitData hit_data = get_min_hit_data(ray);
//     if (hit_data.hittable_index < 0 && amount_of_reflections == 0)
//         return false;
//     else if (amount_of_reflections > MAX_AMOUNT_OF_REFLECTIONS) {
//         *p_color = color_mult_n((ColorRGB) {255, 255, 255}, pow(2, -amount_of_reflections));
//         amount_of_reflections = 0;
//         return true;
//     }

//     amount_of_reflections++;
//     Vec3 normal = get_hittable_normal(hit_data);
//     Ray new_ray = {hit_data.hit_ray.end, vec3_rand_unit_hemisphere(normal)};
//     get_hittable_color(new_ray, p_color);
// }

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
        Vec3 normal = get_hittable_normal(hit_data);
        Ray new_ray = {hit_data.hit_ray.end, vec3_add(hit_data.hit_ray.end, vec3_add(normal, vec3_rand_unit()))};
        return color_mult_n(get_point_color(new_ray, amount_of_reflections - 1), 0.5);
    }
    else {
        ColorRGB color_a = {255, 255, 255}, color_b = {0, 0, 0}; // a - bottom of the image, b - top
        return fcolor_gradient(ray.end.x, -VIEWPORT_W / 2, VIEWPORT_W / 2, color_a, color_b);
    }
}
