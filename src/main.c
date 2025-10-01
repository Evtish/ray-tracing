#include "calc.h"
#include "ui.h"
#include "color.h"
#include "file_utils.h"

#define START_COLOR_VAL 0
#define MAX_COLOR_VAL 255
#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 360
#define IMAGE_W ((int) (IMAGE_H * ASPECT_RATIO))

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, "build/image.ppm", "w");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    fprintf(ppm_image, "P6\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL); // header
    // int i, j;
    for (int i = START_COLOR_VAL; i < IMAGE_H; i++) {
        // int shift = abs_ceil((MAX_COLOR_VAL - START_COLOR_VAL + 1) / IMAGE_H);
        indicate_progress_percent(i, IMAGE_H - START_COLOR_VAL);
        // printf("r: %d ", map(i, 0, IMAGE_H, START_COLOR_VAL, MAX_COLOR_VAL));
        for (int j = START_COLOR_VAL; j < IMAGE_W; j++) {
            // printf("g: %d\n", map(j, 0, IMAGE_W, START_COLOR_VAL, MAX_COLOR_VAL));
            ColorRGB color = {
                map(i, 0, IMAGE_H - 1, START_COLOR_VAL, MAX_COLOR_VAL),
                map(j, 0, IMAGE_W - 1, START_COLOR_VAL, MAX_COLOR_VAL),
                0
            };
            color_write(&color, ppm_image);
        }
    }
    // printf("r: %d ", map(i, 0, IMAGE_H, START_COLOR_VAL, MAX_COLOR_VAL));
    // printf("g: %d\n", map(j, 0, IMAGE_W, START_COLOR_VAL, MAX_COLOR_VAL));
    printf("Done!\n");
    fclose(ppm_image);
    
    return 0;
}