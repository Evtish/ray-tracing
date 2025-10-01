#pragma once

#include <stdio.h>
#include <stdlib.h>

void fopen_safe(FILE **__p_stream, const char *__restrict __filename, const char *__restrict __modes);