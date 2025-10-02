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

    const Vec3 viewport_u = vec3_add(camera_center, (Vec3) {VIEWPORT_W, 0, 0});
    const Vec3 viewport_v = vec3_add(camera_center, (Vec3) {0, -VIEWPORT_H, 0});
    const Vec3 pixel_delta_u = vec3_div_n(viewport_u, IMAGE_W);
    const Vec3 pixel_delta_v = vec3_div_n(viewport_v, IMAGE_H);

    // viewport_upper_left = camera_center - viewport_u / 2 - viewport_v / 2 - (Vec3) {0, 0, focal_length}
    const Vec3 viewport_upper_left = vec3_sub(
        vec3_sub(
            vec3_sub(
                camera_center,
                vec3_div_n(viewport_u, 2)
            ),
            vec3_div_n(viewport_v, 2)
        ),
        (Vec3) {0, 0, FOCAL_LENGTH}
    );
    // pixel_upper_left = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2
    Vec3 pixel_upper_left = vec3_add(
        viewport_upper_left,
        vec3_div_n(
            vec3_add(pixel_delta_u, pixel_delta_v),
            2
        )
    );

    // printf("VIEWPORT_H=%lf, VIEWPORT_W=%lf\nviewport_upper_left=%lf %lf %lf\npixel_upper_left=%lf %lf %lf\n", VIEWPORT_H, VIEWPORT_W, viewport_upper_left.x, viewport_upper_left.y, viewport_upper_left.z, pixel_upper_left.x, pixel_upper_left.y, pixel_upper_left.z);
    unsigned int j = 0;
    for (; j < IMAGE_H; j++) {
        indicate_progress_percent(j, IMAGE_H);

        for (unsigned int i = 0; i < IMAGE_W; i++) {
            // pixel = pixel_upper_left + pixel_delta_u * i + pixel_delta_v * j
            Vec3 pixel = vec3_add(
                vec3_add(
                    pixel_upper_left,
                    vec3_mult_n(pixel_delta_u, i)
                ), vec3_mult_n(pixel_delta_v, j)
            );
            ColorRGB color = get_pixel_color(pixel);
            // ColorRGB color = get_pixel_color_circle(pixel, pixel_upper_left);
            ppm_write_color(&color, ppm_image);
        }
    }
    indicate_progress_percent(j, IMAGE_H);

    fclose(ppm_image);
    
    return 0;
}