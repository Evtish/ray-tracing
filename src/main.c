// #include <time.h>

#include "calc.h"
#include "ui.h"
#include "file_utils.h"

#define HEADER_SIZE 20
#define MAX_COLOR_VAL 255
#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 360
#define IMAGE_W ((int) (IMAGE_H * ASPECT_RATIO))

#define arr_len(arr) (sizeof (arr) / sizeof (arr)[0])

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, "build/image.ppm", "w");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB
    // time_t start_time = time(NULL);

    fprintf(ppm_image, "P6\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL); // header
    for (int i = 0; i < IMAGE_H; i++) {
        indicate_progress_percent(i, IMAGE_H);
        for (int j = 0; j < IMAGE_W; j++) {
            unsigned char color[3] = {
                map(i, 0, IMAGE_H, 0, MAX_COLOR_VAL),
                // i * MAX_COLOR_VAL / (double) (IMAGE_H - 1),
                map(j, 0, IMAGE_W, 0, MAX_COLOR_VAL),
                // j * MAX_COLOR_VAL / (double) (IMAGE_W - 1),
                0
            };
            fwrite(color, sizeof color[0], arr_len(color), ppm_image);
            // fprintf(ppm_image, "%d %d %d\n", r, g, b);
        }
    }
    printf("Done!\n");
    // printf("%ld seconds\n", time(NULL) - start_time);
    fclose(ppm_image);
    
    return 0;
}