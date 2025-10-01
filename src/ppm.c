#include "ppm.h"

void ppm_write_header(FILE *const image) {
    fprintf(image, "P6\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL);
}

void ppm_write_color(ColorRGB *const p_color, FILE *const image) {
    fwrite(p_color, sizeof (unsigned char), 3, image);
}