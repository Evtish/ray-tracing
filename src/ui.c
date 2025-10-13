#include "ui.h"

#define PERCENT_STEP 1

void indicate_progress_percent(int val, int max_val) {
    if (val == 0)
        printf("Rendering the image (%ux%u)...\n", IMAGE_W, IMAGE_H);
    if (val % (max_val * PERCENT_STEP / 100) == 0) {
        printf("\r%d%%", val * 100 / max_val);
        fflush(stdout);
    }
    if (val >= max_val)
        printf("\r");
}
