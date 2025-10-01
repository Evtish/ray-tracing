#include <stdio.h>

#define HEADER_SIZE 20
#define MAX_COLOR_VAL 255
#define ASPECT_RATIO (16 / 9.0)
#define IMAGE_H 360
#define IMAGE_W ((int) (IMAGE_H * ASPECT_RATIO))
#define PERCENT_STEP 5

#define arr_len(arr) (sizeof (arr) / sizeof (arr)[0])

int main(void) {
    const char *file_name = "build/image.ppm";
    FILE *ppm_image = fopen(file_name, "w");
    if (!ppm_image) {
        fprintf(stderr, "Error occured while opening %s\n", file_name);
        return 1;
    }

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 14); // 16 KiB
    
    // char header[HEADER_SIZE];
    // sprintf(header, "P6 %d %d %d ", IMAGE_W, IMAGE_H, MAX_COLOR_VAL);
    // for (size_t i = 0; i < HEADER_SIZE * sizeof header[0]; i++)
    //     putc(header[i], ppm_image);
    fprintf(ppm_image, "P6\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL);

    for (int i = 0; i < IMAGE_H; i++) {
        if (i % (IMAGE_H * PERCENT_STEP / 100) == 0)
            printf("%d%%\n", i * 100 / IMAGE_H);

        for (int j = 0; j < IMAGE_W; j++) {
            char color[3] = {
                i * MAX_COLOR_VAL / (double) (IMAGE_H - 1),
                j * MAX_COLOR_VAL / (double) (IMAGE_W - 1),
                0
            };

            fwrite(color, sizeof color[0], arr_len(color), ppm_image);
            // fprintf(ppm_image, "%d %d %d\n", r, g, b);
        }
    }
    printf("Done!\n");
    fclose(ppm_image);
    
    return 0;
}