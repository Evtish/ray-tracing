#include "image.h"

#define MAX_AMOUNT_OF_REFLECTIONS 50

void image_write_color(ColorRGB *const p_color, FILE *const image) {
    fwrite(p_color, sizeof p_color->r, 3, image);
}

void image_write_header(FILE *const image) {
    fprintf(image, "P6\n%d %d\n%d\n", IMAGE_W, IMAGE_H, MAX_COLOR_VAL);
}

void image_render(FILE *const image) {
    unsigned int j = 0;
    for (; j < IMAGE_H; j++) {
        indicate_progress_percent(j, IMAGE_H);
        for (unsigned int i = 0; i < IMAGE_W; i++) {
            ColorRGB color = get_anti_aliased_pixel_color((Vec2) {i, j}, AMOUNT_OF_HITTABLES);
            color_correct_gamma(&color);
            image_write_color(&color, image);
        }
    }
    indicate_progress_percent(j, IMAGE_H);
}
