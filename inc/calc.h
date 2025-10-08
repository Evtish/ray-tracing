#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define FLOATING_POINT_APPROX_ZERO 1e-50

double flimit(const double val, const double low, const double high);
double fmap(
    const double var,
    const double in_min,
    const double in_max,
    const double out_min,
    const double out_max
);
double prevent_zero_div(const double a, const double b, const double default_val);
bool finterval_surrounds(const double val, const double a, const double b);
bool finterval_contains(const double val, const double a, const double b);
double rand_double(const double low, const double high);
double correct_gamma(const double val);
