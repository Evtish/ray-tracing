#include "color.h"

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

ColorRGB get_hit_data_color(const HitData hit_data) {
    Hittable hittable = scene[hit_data.hittable_index];
    Vec3 normal;
    switch (hittable.type) {
        case SPHERE:
            normal = get_normal(hit_data.hit_ray, hittable.data.sphere.center);
            return (ColorRGB) {
                fmap(normal.x, -1, 1, 0, MAX_COLOR_VAL),
                fmap(normal.y, -1, 1, 0, MAX_COLOR_VAL),
                fmap(normal.z, -1, 1, 0, MAX_COLOR_VAL)
            };
        break;
        default: return (ColorRGB) {0, 0, 0}; break;
    }
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
    // hittable objects
    HitData min_hit_data = get_min_hit_data(point);
    if (min_hit_data.hittable_index >= 0) // if the ray hit
        return get_hit_data_color(min_hit_data);

    // background
    ColorRGB color_a = {255, 255, 255}, color_b = {0, 170, 255}; // a - bottom of the image, b - top
    return fcolor_gradient(point.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, color_a, color_b);
}
