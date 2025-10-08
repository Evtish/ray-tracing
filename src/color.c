#include "color.h"

void color_correct_gamma(ColorRGB *p_color) {
    double r = fmap(p_color->r, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);
    double g = fmap(p_color->g, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);
    double b = fmap(p_color->b, START_COLOR_VAL, MAX_COLOR_VAL, 0, 1);

    double corr_r = correct_gamma(r);
    double corr_g = correct_gamma(g);
    double corr_b = correct_gamma(b);

    *p_color = (ColorRGB) {
        fmap(corr_r, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(corr_g, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL),
        fmap(corr_b, 0, 1, START_COLOR_VAL, MAX_COLOR_VAL)
    };
}

ColorRGB get_point_color(const Ray ray, const int amount_of_reflections) {
    if (amount_of_reflections < 0)
        return (ColorRGB) {0, 0, 0};

    HitData hit_data = get_min_hit_data(ray);
    int hittable_idx = hit_data.hittable_index;
    if (hittable_idx >= 0) {
        Material material = scene[hittable_idx].material;
        Vec3 normal = get_hittable_normal(hit_data),
        reflected_ray_origin = hit_data.hit_point,
        reflected_ray_dir;
        switch (material.reflection_type) {
            default:
            case DIFFUSE:
                reflected_ray_dir = vec3_add(normal, vec3_rand_unit());
            break;
            case SPECULAR:
                // reflected_ray_dir = dir - 2 * dot(normal, dir) * normal
                reflected_ray_dir = vec3_sub(ray.dir, vec3_mult_n(normal, 2 * vec3_dot(normal, ray.dir)));
                // reflected_ray_dir = vec3_sub(ray.origin, vec3_mult_n(normal, 2 * vec3_dot(normal, ray.origin)));
                // reflected_ray_dir = vec3_normalize(vec3_add(
                //     vec3_mult_n(vec3_sub(hit_data.hit_point, ray.origin), 2),
                //     vec3_mult_n(normal, 2 * vec3_dot(normal, ray.origin))
                // ));
            break;
        }
        Ray reflected_ray = {reflected_ray_origin, reflected_ray_dir};
        // return color_blend(
        //     get_point_color(reflected_ray, amount_of_reflections - 1),
        //     material.color,
        //     material.albedo
        // );
        return color_mult_color(get_point_color(reflected_ray, amount_of_reflections - 1), material.albedo);
    }
    
    else {
        ColorRGB color_a = {128, 179, 255}, color_b = {255, 255, 255}; // a - top of the image, b - bottom
        double blend_k = fmap(ray.dir.y, -VIEWPORT_H / 2, VIEWPORT_H / 2, 0, 1);
        return color_blend(color_a, color_b, blend_k);
    }
}
