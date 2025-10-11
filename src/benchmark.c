#include "benchmark.h"

double benchmark_render(void (*render_func)(FILE *const image), FILE *const image) {
    clock_t start = clock();
    render_func(image);
    return (clock() - start) / (double) CLOCKS_PER_SEC;
}
