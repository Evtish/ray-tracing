#include "ui.h"

#define PERCENT_STEP 5

void indicate_progress_percent(int val, int max_val) {
    if (val % (max_val * PERCENT_STEP / 100) == 0)
        printf("%d%%\n", val * 100 / max_val);
}