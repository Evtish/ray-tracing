#include "calc.h"

// limit var to a range low -- high
int limit(const int val, const int low, const int high) {
    if (val > high)
        return high;
    else if (val < low)
        return low;
    else
        return val;
}

// change a range of var from low1 -- high1 to low2 -- high2
int map(const int var, const int low1, const int high1, const int low2, const int high2) {
    int d1 = high1 - low1 + 1, d2 = high2 - low2 + 1, res = 0;
    
    if (d2 >= d1)
        res = low2 + (var - low1) * (d2 / d1);
    else
        res = low2 + (var - low1) / (d1 / d2);
    
    return limit(res, low2, high2);
}