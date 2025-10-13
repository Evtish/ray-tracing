#include "anti_aliasing.h"

/*
0. do not use anti-aliasing - significantly faster, many black pixels remain on the image
1. arithmetic mean of colors
2. blend colors - preferred mode. slightly slower, but slightly more accurate than the previous one
*/
#define ANTI_ALIASING_MODE 2

#define SAMPLES_PER_PIXEL 50

ColorRGB get_anti_aliased_pixel_color(const Vec2 pixel, const int amount_of_reflections) {
    #if ANTI_ALIASING_MODE == 0
        Vec3 point = viewport_get_point_from_pixel(pixel);
        Ray ray = {camera_center, vec3_normalize(vec3_sub(point, camera_center))};
        return get_point_color(ray, amount_of_reflections);

    #elif ANTI_ALIASING_MODE == 1
        IntColorRGB large_color = {0, 0, 0};
        for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
            Vec2 offset = vec2_rand_unit_square();
            Vec3 point = viewport_get_point_from_pixel(vec2_add(pixel, offset));
            Ray ray = {camera_center, vec3_normalize(vec3_sub(point, camera_center))};
            large_color_increase(&large_color, get_point_color(ray, amount_of_reflections));
        }
        return large_color_div_n(large_color, SAMPLES_PER_PIXEL);
        
    #elif ANTI_ALIASING_MODE == 2
        Vec3 mapped_color = {0, 0, 0};
        for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
            double blend_k = (double) sample / (sample + 1);
            Vec2 offset = vec2_rand_unit_square();
            Vec3 point = viewport_get_point_from_pixel(vec2_add(pixel, offset));
            Ray ray = {camera_center, vec3_normalize(vec3_sub(point, camera_center))};
            ColorRGB sample_color = get_point_color(ray, amount_of_reflections);
            Vec3 mappped_sample_color = {
                fmap(sample_color.r, MIN_COLOR_VAL, MAX_COLOR_VAL, 0, 1),
                fmap(sample_color.g, MIN_COLOR_VAL, MAX_COLOR_VAL, 0, 1),
                fmap(sample_color.b, MIN_COLOR_VAL, MAX_COLOR_VAL, 0, 1)
            };
            mapped_color = vec3_add(vec3_mult_n(mapped_color, blend_k), vec3_mult_n(mappped_sample_color, 1 - blend_k));
        }
        return (ColorRGB) {
            fmap(mapped_color.x, 0, 1, MIN_COLOR_VAL, MAX_COLOR_VAL),
            fmap(mapped_color.y, 0, 1, MIN_COLOR_VAL, MAX_COLOR_VAL),
            fmap(mapped_color.z, 0, 1, MIN_COLOR_VAL, MAX_COLOR_VAL)
        };
    #endif
}
