#pragma once

#include <stdio.h>

#include "vec3.h"

typedef DVec3 ColorRGB;

void color_write(ColorRGB *const p_color, FILE *const stream);