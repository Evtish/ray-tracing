#include "color_rgb.h"

ColorRGB color_add(const ColorRGB u, const ColorRGB v) { return (ColorRGB) {u.r + v.r, u.g + v.g, u.b + v.b}; }

ColorRGB color_mult_color(const ColorRGB u, const ColorRGB v) {
    int new_r = u.r * v.r;
    int new_g = u.g * v.g;
    int new_b = u.b * v.b;

    return (ColorRGB) {
        fmap(new_r, START_COLOR_VAL, MAX_COLOR_VAL * MAX_COLOR_VAL, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(new_g, START_COLOR_VAL, MAX_COLOR_VAL * MAX_COLOR_VAL, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(new_b, START_COLOR_VAL, MAX_COLOR_VAL * MAX_COLOR_VAL, START_COLOR_VAL, MAX_COLOR_VAL)
    };
}

ColorRGB color_mult_n(const ColorRGB u, const double n) { return (ColorRGB) {u.r * n, u.g * n, u.b * n}; }

// a * k + b * (1 - k)
ColorRGB color_blend(const ColorRGB a, const ColorRGB b, const double k) {
    return color_add(
        color_mult_n(a, k),
        color_mult_n(b, 1 - k)
    );
}
