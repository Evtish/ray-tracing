#include "calc.h"
#include "ui.h"
#include "file_utils.h"
#include "ppm.h"
#include "viewport.h"

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, IMAGE_NAME, "wb");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    ppm_write_header(ppm_image);

    // printf("VIEWPORT_H=%lf, VIEWPORT_W=%lf\nviewport_upper_left=%lf %lf %lf\npixel_upper_left=%lf %lf %lf\n", VIEWPORT_H, VIEWPORT_W, viewport_upper_left.x, viewport_upper_left.y, viewport_upper_left.z, pixel_upper_left.x, pixel_upper_left.y, pixel_upper_left.z);
    unsigned int j = 0;
    for (; j < IMAGE_H; j++) {
        indicate_progress_percent(j, IMAGE_H);

        for (unsigned int i = 0; i < IMAGE_W; i++) {
            Vec3 pixel_in_3d = viewport_get_vector_from_pixel((Vec2) {i, j});
            ColorRGB color = get_pixel_color(pixel_in_3d);
            // ColorRGB color = get_pixel_color_circle(pixel_in_3d, viewport_get_vector_from_pixel((Vec2) {0, 0}));
            ppm_write_color(&color, ppm_image);
        }
    }
    indicate_progress_percent(j, IMAGE_H);

    fclose(ppm_image);
    
    return 0;
}