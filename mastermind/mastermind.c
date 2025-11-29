
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"
#include "colors.h"
#include "combo.h"
#include "gamestate.h"
#include "display.h"

int initGame(Combo* soluce) {

    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    Color availableColors[6] = {
        COLOR_Y, COLOR_B, COLOR_R, COLOR_G, COLOR_W, COLOR_P
    };

    // on initialise la solution a deviner
    for (int i = 0; i < 4; i++) {
        int colorPosition = rand() % 6;
        soluce->attempt[i] = availableColors[colorPosition];
        soluce->result[i] = SOL_UNCHECKED;
    }

    return 0;
}

int turn(Gamestate* gameState) {
    
    //ask the player to guess
    Combo* currentguess = getPlayerGuess();

    //ask for verification
	gameState->history[gameState->turn] = *currentguess;
	int status = checkCombinaison(gameState);

    //show result
    showCombo(currentguess);
    free(currentguess);

    return status;
}

Combo* getPlayerGuess() {
    Combo* playerCombo = (Combo*)malloc(sizeof(Combo));
    askPlayerToGuess(playerCombo);
    return playerCombo;
}