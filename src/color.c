#include "color.h"

#define MAX_AMOUNT_OF_REFLECTIONS 10

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

bool get_hittable_color(const Ray ray, ColorRGB *p_color) {
    // static bool was_hit = false;
    static int amount_of_reflections = 0;

    HitData hit_data = get_min_hit_data(ray);
    if (hit_data.hittable_index < 0 && amount_of_reflections == 0) // if the ray has not hit at first time
        return false;

    Hittable hittable = scene[hit_data.hittable_index];
    Vec3 normal;
    switch (hittable.hittable_type) {
        case SPHERE:
            normal = get_normal(hit_data.hit_ray.end, hittable.sphere.center);
            *p_color = (ColorRGB) {
                fmap(normal.x, -1, 1, 0, MAX_COLOR_VAL),
                fmap(normal.y, -1, 1, 0, MAX_COLOR_VAL),
                fmap(normal.z, -1, 1, 0, MAX_COLOR_VAL)
            };
        break;
        default: *p_color = (ColorRGB) {0, 0, 0}; break;
    }

    return true;
}

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

ColorRGB get_point_color(const Vec3 point) {
    ColorRGB color;

    if (!get_hittable_color((Ray) {camera_center, point}, &color)) {
        ColorRGB color_a = {255, 255, 255}, color_b = {0, 170, 255}; // a - bottom of the image, b - top
        color = fcolor_gradient(point.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, color_a, color_b);
    }

    return color;
}
