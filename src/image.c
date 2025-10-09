#include "image.h"

#define MAX_AMOUNT_OF_REFLECTIONS 50
#define SAMPLES_PER_PIXEL 100

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
            IntColorRGB large_color = {0, 0, 0};
            for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
                Vec2 offset = vec2_rand_unit_square(), pixel = vec2_add((Vec2) {i, j}, offset);
                Vec3 point = viewport_get_point_from_pixel(pixel);
                Ray ray = {camera_center, vec3_sub(point, camera_center)};
                large_color_increase(&large_color, get_point_color(ray, MAX_AMOUNT_OF_REFLECTIONS));
            }
            ColorRGB color = large_color_div_n(large_color, SAMPLES_PER_PIXEL);
            // Vec3 point = viewport_get_point_from_pixel((Vec2) {i, j});
            // Ray ray = {camera_center, vec3_sub(point, camera_center)};
            // ColorRGB color = get_point_color(ray, MAX_AMOUNT_OF_REFLECTIONS);

            color_correct_gamma(&color);
            image_write_color(&color, image);
        }
    }
    indicate_progress_percent(j, IMAGE_H);
}
