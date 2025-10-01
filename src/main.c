#include <stdio.h>

#define MAX_COLOR_VAL 255
#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 360
#define IMAGE_W ((int) (IMAGE_H * ASPECT_RATIO))
#define PERCENT_STEP 5

int main(void) {
    const char *file_name = "build/image.ppm";
    FILE *image_file = fopen(file_name, "w");
    if (!image_file) {
        fprintf(stderr, "Error occured while opening %s\n", file_name);
        return 1;
    }

    setvbuf(image_file, NULL, _IOFBF, 1 << 13); // 8 KiB
    
    fprintf(image_file, "P3\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL);

    for (int i = 0; i < IMAGE_H; i++) {
        if (i % (IMAGE_H * PERCENT_STEP / 100) == 0)
            printf("%d%%\n", i * 100 / IMAGE_H);

        for (int j = 0; j < IMAGE_W; j++) {
            int r = i * MAX_COLOR_VAL / (double) (IMAGE_H - 1);
            int g = j * MAX_COLOR_VAL / (double) (IMAGE_W - 1);
            int b = 0;

            fprintf(image_file, "%d %d %d\n", r, g, b);
        }
    }
    printf("Done!\n");
    fclose(image_file);
    
    return 0;
}