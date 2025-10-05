#include "vec3.h"

double vec3_len(const Vec3 u) { return sqrt(u.x * u.x + u.y * u.y + u.z * u.z); }

double vec3_dot(const Vec3 u, const Vec3 v) { return u.x * v.x + u.y * v.y + u.z * v.z; }

Vec3 vec3_normalize(const Vec3 u) {
    double len = vec3_len(u);
    return (Vec3) {
        prevent_zero_div(u.x, len, 0),
        prevent_zero_div(u.y, len, 0),
        prevent_zero_div(u.z, len, 0)
    };
}

Vec3 vec3_add(const Vec3 u, const Vec3 v) { return (Vec3) {u.x + v.x, u.y + v.y, u.z + v.z}; }

Vec3 vec3_sub(const Vec3 u, const Vec3 v) { return (Vec3) {u.x - v.x, u.y - v.y, u.z - v.z}; }

Vec3 vec3_mult_n(const Vec3 u, const double n) { return (Vec3) {u.x * n, u.y * n, u.z * n}; }

Vec3 vec3_div_n(const Vec3 u, const double n) { return (Vec3) {u.x / n, u.y / n, u.z / n}; }
