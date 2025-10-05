#pragma once

#include <math.h>

double flimit(const double val, const double low, const double high);
double fmap(
    const double var,
    const double in_min,
    const double in_max,
    const double out_min,
    const double out_max
);
double prevent_zero_div(const double a, const double b, const double default_val);
