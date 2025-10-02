#include "color.h"

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

// ColorRGB get_pixel_color_circle(const Vec3 pixel, const Vec3 circle_center) {
//     const double circle_radius = 5.0;
//     double dist = fabs(vec3_len(vec3_sub(pixel, circle_center)));
//     double blend_k = fmap(dist, 0, circle_radius, 0, 1);
//     ColorRGB color_a = {0, 170, 255}, color_b = {255, 255, 255}; // a - inside, b - outside

//     // color_a * (1 - blend_k) + color_b * blend_k
//     return color_add(
//         color_mult_n(color_a, 1 - blend_k),
//         color_mult_n(color_b, blend_k)
//     );
// }

ColorRGB get_pixel_color(const Vec3 pixel) {
    Vec3 sphere_center = {0, 0, -1};
    double sphere_radius = 0.5;
    double hit = hit_sphere(sphere_center, sphere_radius, pixel);
    if (hit > 0) {
        Vec3 hit_ray = get_ray(camera_center, pixel, hit);
        Vec3 normal = vec3_normalize(vec3_sub(hit_ray, sphere_center));
        return (ColorRGB) {
            fmap(normal.x, -1, 1, 0, MAX_COLOR_VAL),
            fmap(normal.y, -1, 1, 0, MAX_COLOR_VAL),
            fmap(normal.z, -1, 1, 0, MAX_COLOR_VAL)
        };
    }

    double blend_k = fmap(pixel.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, 0, 1);
    ColorRGB color_a = {255, 255, 255}, color_b = {0, 170, 255}; // a - bottom, b - top

    // color_a * (1 - blend_k) + color_b * blend_k
    return color_add(
        color_mult_n(color_a, 1 - blend_k),
        color_mult_n(color_b, blend_k)
    );
}
