#include "vec2.h"

double vec2_len(const Vec2 u) { return sqrt(u.x * u.x + u.y * u.y); }

double vec2_dot(const Vec2 u, const Vec2 v) { return u.x * v.x + u.y * v.y; }

Vec2 vec2_normalize(const Vec2 u) {
    double len = vec2_len(u);
    return (Vec2) {
        prevent_zero_div(u.x, len, 0),
        prevent_zero_div(u.y, len, 0)
    };
}

Vec2 vec2_limit(const Vec2 u, const Vec2 min, const Vec2 max) {
    return (Vec2) {
        flimit(u.x, min.x, max.x),
        flimit(u.y, min.y, max.y)
    };
}

Vec2 vec2_add(const Vec2 u, const Vec2 v) { return (Vec2) {u.x + v.x, u.y + v.y}; }

Vec2 vec2_sub(const Vec2 u, const Vec2 v) { return (Vec2) {u.x - v.x, u.y - v.y}; }

Vec2 vec2_mult_n(const Vec2 u, const double n) { return (Vec2) {u.x * n, u.y * n}; }

Vec2 vec2_div_n(const Vec2 u, const double n) { return (Vec2) {u.x / n, u.y / n}; }

DVec2 dvec2_add(const DVec2 u, const DVec2 v) { return (DVec2) {u.x + v.x, u.y + v.y}; }

DVec2 dvec2_mult_n(const DVec2 u, const double n) { return (DVec2) {u.x * n, u.y * n}; }
