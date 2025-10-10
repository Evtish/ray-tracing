#include "vec3.h"

double vec3_dot(const Vec3 u, const Vec3 v) { return u.x * v.x + u.y * v.y + u.z * v.z; }

double vec3_len(const Vec3 u) { return sqrt(u.x * u.x + u.y * u.y + u.z * u.z); }

Vec3 vec3_normalize(const Vec3 u) {
    double len = vec3_len(u);
    return (Vec3) {
        prevent_zero_div(u.x, len, 0),
        prevent_zero_div(u.y, len, 0),
        prevent_zero_div(u.z, len, 0)
    };
}

Vec3 vec3_rand_unit_circle(void) {
    Vec3 u;
    double u_squared_len;
    do {
        u = (Vec3) {rand_double(-1, 1), rand_double(-1, 1), rand_double(-1, 1)};
        u_squared_len = vec3_squared_len(u);
    } while (FLOATING_POINT_APPROX_ZERO > u_squared_len || u_squared_len > 1);
    return vec3_normalize(u);
}

Vec3 vec3_rand_unit_hemisphere(const Vec3 normal) {
    Vec3 u = vec3_rand_unit_circle();
    if (vec3_dot(u, normal) < 0) // if u isn't in the same hemisphere as the normal
        return vec3_mult_n(u, -1);
    return u;
}

Vec3 vec3_add(const Vec3 u, const Vec3 v) { return (Vec3) {u.x + v.x, u.y + v.y, u.z + v.z}; }

Vec3 vec3_sub(const Vec3 u, const Vec3 v) { return (Vec3) {u.x - v.x, u.y - v.y, u.z - v.z}; }

Vec3 vec3_mult_n(const Vec3 u, const double n) { return (Vec3) {u.x * n, u.y * n, u.z * n}; }

Vec3 vec3_div_n(const Vec3 u, const double n) { return (Vec3) {u.x / n, u.y / n, u.z / n}; }

bool vec3_near_zero(const Vec3 u) {
    return (
        fabs(u.x) < FLOATING_POINT_APPROX_ZERO &&
        fabs(u.y) < FLOATING_POINT_APPROX_ZERO &&
        fabs(u.z) < FLOATING_POINT_APPROX_ZERO
    );
}
