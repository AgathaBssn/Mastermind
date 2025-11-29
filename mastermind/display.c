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

void askPlayerToGuess(Combo* playerCombo) {
    char input[5] = "    ";
    printf("Enter your guess (4 letters among Y, B, R, G, W, P): ");
    scanf_s("%4s", input, 5);
    for (int i = 0; i < 4; i++) {
        playerCombo->attempt[i] = (Color)input[i];
        playerCombo->result[i] = SOL_UNCHECKED;
    }
}

void sayBye() {
    printf("\n Thank you for playing with me");
}