#include "viewport.h"

// Vec2 viewport_get_pixel(Vec3 u) {
//     Vec3 camera_center = {0, 0, 0};
//     const double focal_length = 1.0;

//     const Vec3 viewport_u = vec3_add(camera_center, (Vec3) {VIEWPORT_W, 0, 0});
//     const Vec3 viewport_v = vec3_add(camera_center, (Vec3) {0, -VIEWPORT_H, 0});
//     const Vec3 pixel_delta_u = vec3_div_n(viewport_u, IMAGE_W);
//     const Vec3 pixel_delta_v = vec3_div_n(viewport_v, IMAGE_H);

//     // viewport_upper_left = camera_center - viewport_u / 2 + viewport_v / 2 - (Vec3) {0, 0, focal_length}
//     const Vec3 viewport_upper_left = vec3_sub(
//         vec3_add(
//             vec3_sub(
//                 camera_center,
//                 vec3_div_n(viewport_u, 2)
//             ),
//             vec3_div_n(viewport_v, 2)
//         ),
//         (Vec3) {0, 0, focal_length}
//     );
//     // pixel_upper_left = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2
//     Vec3 pixel_upper_left = vec3_add(
//         viewport_upper_left,
//         vec3_div_n(
//             vec3_add(pixel_delta_u, pixel_delta_v),
//             2
//         )
//     );


// }