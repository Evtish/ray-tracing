#include <time.h>

#include "file_utils.h"
#include "image.h"
#include "benchmark.h"

#define BENCHMARK true // true - print time spent rendering the image

int main(void) {
    srand(time(NULL));
    
    FILE *ppm_image;
    fopen_safe(&ppm_image, IMAGE_NAME, "wb");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    image_write_header(ppm_image);

    #if BENCHMARK
        double time_passed = benchmark_render(image_render, ppm_image);
        printf("Time spent: %.3lf second(s)\n", time_passed);
    #else
        image_render(ppm_image);
    #endif
    
    fclose(ppm_image);
    
    return 0;
}
