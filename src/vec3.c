#include "vec3.h"

double vec3_len(const Vec3 u) { return sqrt(u.x * u.x + u.y * u.y + u.z * u.z); }

DVec3 vec3_normalize(const Vec3 u) {
    return (DVec3) {
        prevent_zero_div(u.x, fabs(u.x), 0),
        prevent_zero_div(u.y, fabs(u.y), 0),
        prevent_zero_div(u.z, fabs(u.z), 0)
    };
}

DVec3 dvec3_add(const DVec3 u, const DVec3 v) { return (DVec3) {u.x + v.x, u.y + v.y, u.z + v.z}; }

DVec3 dvec3_mult_n(const DVec3 u, const double n) { return (DVec3) {u.x * n, u.y * n, u.z * n}; }

Vec3 vec3_limit(const Vec3 u, const Vec3 min, const Vec3 max) {
    return (Vec3) {
        flimit(u.x, min.x, max.x),
        flimit(u.y, min.y, max.y),
        flimit(u.z, min.z, max.z)
    };
}

Vec3 vec3_add(const Vec3 u, const Vec3 v) { return (Vec3) {u.x + v.x, u.y + v.y, u.z + v.z}; }

Vec3 vec3_sub(const Vec3 u, const Vec3 v) { return (Vec3) {u.x - v.x, u.y - v.y, u.z - v.z}; }

Vec3 vec3_mult_n(const Vec3 u, const double n) { return (Vec3) {u.x * n, u.y * n, u.z * n}; }

Vec3 vec3_div_n(const Vec3 u, const double n) { return (Vec3) {u.x / n, u.y / n, u.z / n}; }

double vec3_dot(const Vec3 u, const Vec3 v) { return u.x * v.x + u.y * v.y + u.z * v.z; }