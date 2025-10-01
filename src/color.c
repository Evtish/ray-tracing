#include "color.h"

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

// ColorRGB get_pixel_color_circle(const Vec3 pixel, const Vec3 circle_center) {
//     const double circle_radius = 0.5;
//     double dist = fabs(vec3_len(vec3_sub(pixel, circle_center)));
//     double blend_k = fmap(dist, 0, circle_radius, 0, 1);
//     ColorRGB color_a = {255, 0, 0}, color_b = {0, 0, 0};

//     // unsigned char r = 0 * (1 - blend_k) + 255 * blend_k;
//     // unsigned char g = 100 * (1 - blend_k) + 255 * blend_k;
//     // unsigned char b = 255 * (1 - blend_k) + 255 * blend_k;

//     // color_a * (1 - blend_k) + color_b * blend_k
//     return dvec3_add(
//         dvec3_mult_n(color_a, 1 - blend_k),
//         dvec3_mult_n(color_b, blend_k)
//     );
//     // return (ColorRGB) {r, g, b};
// }

ColorRGB get_pixel_color(const Vec3 pixel) {
    double blend_k = fmap(pixel.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, 0, 1);
    ColorRGB color_a = {255, 255, 255}, color_b = {0, 170, 255}; // a - bottom, b - top

    // color_a * (1 - blend_k) + color_b * blend_k
    ColorRGB blended_color = color_add(
        color_mult_n(color_a, 1 - blend_k),
        color_mult_n(color_b, blend_k)
    );

    return blended_color;
    // return (ColorRGB) {r, g, b};
}