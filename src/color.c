#include "color.h"

ColorRGB get_pixel_color_circle(const Vec3 pixel, const Vec3 circle_center) {
    const double circle_radius = 0.5;
    double dist = fabs(vec3_len(vec3_sub(pixel, circle_center)));
    double blend_k = fmap(dist, 0, circle_radius, 0, 1);
    ColorRGB color_a = {255, 0, 0}, color_b = {0, 0, 0};

    // unsigned char r = 0 * (1 - blend_k) + 255 * blend_k;
    // unsigned char g = 100 * (1 - blend_k) + 255 * blend_k;
    // unsigned char b = 255 * (1 - blend_k) + 255 * blend_k;

    // color_a * (1 - blend_k) + color_b * blend_k
    return dvec3_add(
        dvec3_mult_n(color_a, 1 - blend_k),
        dvec3_mult_n(color_b, blend_k)
    );
    // return (ColorRGB) {r, g, b};
}