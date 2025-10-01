#include "color.h"

void color_write(ColorRGB *const p_color, FILE *const stream) {
    fwrite(p_color, sizeof p_color->x, 3, stream);
}