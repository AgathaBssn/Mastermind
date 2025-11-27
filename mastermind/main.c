#include <stdio.h>
#include "combo.h"
#include "display.h"

int main(void) {
    int stillPlaying = 0;

    stillPlaying = askToPlay();

    if (stillPlaying) {
        Combo x = {
        { COLOR_UNDEF, COLOR_UNDEF, COLOR_UNDEF, COLOR_UNDEF },
        { SOL_UNCHECKED, SOL_UNCHECKED, SOL_UNCHECKED, SOL_UNCHECKED }
        };

        showCombo(&x);

        x.attempt[0] = COLOR_R;
        x.attempt[1] = COLOR_G;
        x.attempt[2] = COLOR_B;
        x.attempt[3] = COLOR_Y;

        x.result[0] = SOL_PARTIAL;
        x.result[1] = SOL_CORRECT;

        showCombo(&x);
    }
    sayBye();
    

    return 0;
}
