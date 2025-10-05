#include "ui.h"
#include "file_utils.h"
#include "ppm.h"
#include "viewport.h"

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, IMAGE_NAME, "wb");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    ppm_write_header(ppm_image);

    unsigned int j = 0;
    for (; j < IMAGE_H; j++) {
        indicate_progress_percent(j, IMAGE_H);

        for (unsigned int i = 0; i < IMAGE_W; i++) {
            Vec3 point = viewport_get_point_from_pixel((Vec2) {i, j});
            ColorRGB color = get_point_color(point);
            ppm_write_color(&color, ppm_image);
        }
    }
    indicate_progress_percent(j, IMAGE_H);

    fclose(ppm_image);
    
    return 0;
}
