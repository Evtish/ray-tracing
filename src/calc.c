#include "calc.h"

#define GAMMA_CORRECTION_DEGREE 0.45 // = 1/2.2

// limit var to a range low -- high
double flimit(const double val, const double low, const double high) {
    if (val > high)
        return high;
    else if (val < low)
        return low;
    else
        return val;
}

// change range of var from in_min -- in_max to out_min -- out_max
double fmap(
    const double var,
    const double in_min,
    const double in_max,
    const double out_min,
    const double out_max
) {
    double d1 = in_max - in_min, d2 = out_max - out_min;
    double res = out_min + (var - in_min) * (d2 / d1);
    
    return flimit(res, out_min, out_max);
}

// prevent zero division
double prevent_zero_div(const double a, const double b, const double default_val) {
    if (fabs(b) < FLOATING_POINT_APPROX_ZERO)
        return default_val;
    else
        return a / b;
}

bool finterval_surrounds(const double val, const double a, const double b) {
    return a < val && val < b;
}

bool finterval_contains(const double val, const double a, const double b) {
    return a <= val && val <= b;
}

// get a random double from a range [low, hight)
double rand_double(const double low, const double high) {
    return fmap(rand(), 0, RAND_MAX + 1U, low, high);
}

double correct_gamma(const double val) {
    if (val > 0)
        return pow(val, GAMMA_CORRECTION_DEGREE);
    return 0;
}