#pragma once

#include <math.h>

#define arr_len(arr) (sizeof (arr) / sizeof (arr)[0])

#define ALMOST_INF 1e14 // arbitrary huge number

double hypotenuse(const int a, const int b);
int abs_ceil(const double n);
int limit(const int val, const int low, const int high);
double flimit(const double val, const double low, const double high);
int map(
    const int var,
    const int in_min,
    const int in_max,
    const int out_min,
    const int out_max
);
double fmap(
    const double var,
    const double in_min,
    const double in_max,
    const double out_min,
    const double out_max
);
double prevent_zero_div(const double a, const double b, const double default_val);