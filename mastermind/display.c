#include "combo.h"
#include "display.h"

#include <stdio.h>
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

int askToPlay() {
    char prompt = ' ';
    int choice = 0;
    printf("Do you want to play ? Y/N \n");
    scanf_s(" %c", &prompt, 1);
    if (prompt == 'Y') {
        //TODO launch the game;
        choice = 1;
    }
    else if (prompt == 'N') {
        choice = 0;
    }
    else {
        askToPlay();
    }
    return choice;
}