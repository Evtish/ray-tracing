#pragma once

#include <time.h>
#include <stdio.h>

double benchmark_render(void (*render_func)(FILE *const image), FILE *const image);
