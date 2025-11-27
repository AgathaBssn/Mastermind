#include <stdio.h>
#include "combo.h"

void showCombo(const Combo* combo) {
    //colors
    for (int i = 0; i < 4; i++) {
        printf("%c ", (char)combo->attempt[i]);
    }
    printf("| ");
    // states
    for (int i = 0; i < 4; i++) {
        printf("%c ", (char)combo->result[i]);
    }
    printf("\n");
}
