#include "calc.h"
#include "ui.h"
#include "file_utils.h"
#include "ppm.h"

#define VIEWPORT_H 2.0
#define VIEWPORT_W (VIEWPORT_H * IMAGE_W / IMAGE_H)

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, IMAGE_NAME, "wb");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    ppm_write_header(ppm_image);

    double focal_length = 1.0;
    Vec3 camera_center = {0, 0, 0};
    Vec3 viewport_u = {VIEWPORT_W, 0, 0};
    Vec3 viewport_v = {0, -VIEWPORT_H, 0};
    Vec3 pixel_delta_u = vec3_div_n(viewport_u, IMAGE_W);
    Vec3 pixel_delta_v = vec3_div_n(viewport_v, IMAGE_H);
    // viewport_upper_left = camera_center - viewport_u / 2 + viewport_v / 2 - (Vec3) {0, 0, focal_length}
    Vec3 viewport_upper_left = vec3_sub(
        vec3_add(
            vec3_sub(
                camera_center,
                vec3_div_n(viewport_u, 2)
            ),
            vec3_div_n(viewport_v, 2)
        ),
        (Vec3) {0, 0, focal_length}
    );
    // pixel_upper_left = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2
    Vec3 pixel_upper_left = vec3_add(
        viewport_upper_left,
        vec3_div_n(
            vec3_add(pixel_delta_u, pixel_delta_v),
            2
        )
    );

    for (int i = START_COLOR_VAL; i < IMAGE_H; i++) {
        indicate_progress_percent(i, IMAGE_H - START_COLOR_VAL);

        for (int j = START_COLOR_VAL; j < IMAGE_W; j++) {
            // pixel = pixel_upper_left + pixel_delta_u * j + pixel_delta_v * i
            Vec3 pixel = vec3_add(
                vec3_add(
                    pixel_upper_left,
                    vec3_mult_n(pixel_delta_u, j)
                ), vec3_mult_n(pixel_delta_v, i)
            );
            ColorRGB color = get_pixel_color_circle(pixel, vec3_add(
                vec3_add(
                    pixel_upper_left,
                    vec3_mult_n(pixel_delta_u, 2 * IMAGE_W / 3)
                ), vec3_mult_n(pixel_delta_v, 2 * IMAGE_H / 5)
            ));
            ppm_write_color(&color, ppm_image);
        }
    }

    printf("Done!\n");

    fclose(ppm_image);
    
    return 0;
}