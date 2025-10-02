#include "calc.h"

#define FLOATING_POINT_APPROX_ZERO 0.00001

double hypotenuse(const int a, const int b) {
    return sqrt(a * a + b * b);
}

int abs_ceil(const double n) {
    if (fabs(n) < FLOATING_POINT_APPROX_ZERO) return 0;
    else if (n > 0.0) return (int)ceil(n);
    else return (int)floor(n);
}

// limit var to a range low -- high
int limit(const int val, const int low, const int high) {
    if (val > high)
        return high;
    else if (val < low)
        return low;
    else
        return val;
}

// limit var to a range low -- high
double flimit(const double val, const double low, const double high) {
    if (val > high)
        return high;
    else if (val < low)
        return low;
    else
        return val;
}

// change a range of var from in_min -- in_max to out_min -- out_max
int map(
    const int var,
    const int in_min,
    const int in_max,
    const int out_min,
    const int out_max
) {
    int d1 = in_max - in_min, d2 = out_max - out_min, res = 0;
    
    if (d2 >= d1)
        res = out_min + (var - in_min) * (d2 / d1);
    else
        res = out_min + (var - in_min) / (d1 / d2);
    
    return limit(res, out_min, out_max);
}

// change range of var from in_min -- in_max to out_min -- out_max
double fmap(
    const double var,
    const double in_min,
    const double in_max,
    const double out_min,
    const double out_max
) {
    double d1 = in_max - in_min, d2 = out_max - out_min, res = 0.0;
    res = out_min + (var - in_min) * (d2 / d1);
    
    return flimit(res, out_min, out_max);
}

// prevent zero division
double prevent_zero_div(const double a, const double b, const double default_val) {
    if (fabs(b) < FLOATING_POINT_APPROX_ZERO)
        return default_val;
    else
        return a / b;
}