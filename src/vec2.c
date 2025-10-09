#include "vec2.h"

Vec2 vec2_rand_unit_square(void) { return (Vec2) {rand_double(-0.5, 0.5), rand_double(-0.5, 0.5)}; }

Vec2 vec2_add(const Vec2 u, const Vec2 v) { return (Vec2) {u.x + v.x, u.y + v.y}; }