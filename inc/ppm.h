#pragma once

#include <stdio.h>

#include "color.h"

void ppm_write_header(FILE *const image);
void ppm_write_color(ColorRGB *const p_color, FILE *const image);