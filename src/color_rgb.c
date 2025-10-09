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

void large_color_increase(IntColorRGB *const u, const ColorRGB v) {
    u->r += v.r;
    u->g += v.g;
    u->b += v.b;
}

ColorRGB large_color_div_n(const IntColorRGB u, const double n) { return (ColorRGB) {u.r / n, u.g / n, u.b / n}; }

void color_correct_gamma(ColorRGB *const p_color) {
    double r = fmap(p_color->r, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);
    double g = fmap(p_color->g, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);
    double b = fmap(p_color->b, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);

    double corr_r = correct_gamma(r);
    double corr_g = correct_gamma(g);
    double corr_b = correct_gamma(b);

    *p_color = (ColorRGB) {
        fmap(corr_r, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(corr_g, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(corr_b, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL)
    };
}
