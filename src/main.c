#include "file_utils.h"
#include "image.h"

int main(void) {
    FILE *ppm_image;
    fopen_safe(&ppm_image, IMAGE_NAME, "wb");

    setvbuf(ppm_image, NULL, _IOFBF, 1 << 16); // 64 KiB

    image_write_header(ppm_image);
    image_render(ppm_image);
    
    fclose(ppm_image);
    
    return 0;
}
