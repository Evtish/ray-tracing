#include "file_utils.h"

void fopen_safe(FILE **__p_stream, const char *__restrict __filename, const char *__restrict __modes) {
    *__p_stream = fopen(__filename, __modes);
    if (!*__p_stream) {
        fprintf(stderr, "Error occured while opening %s\n", __filename);
        exit(1);
    }
}
