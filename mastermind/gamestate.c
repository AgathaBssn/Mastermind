#include <stdlib.h>
#include "gamestate.h"



Gamestate* initGameState(Combo* soluce) {
	// allocation
	Gamestate* gameState = (Gamestate*)malloc(sizeof(Gamestate));
	//init turn
	gameState->turn = 0;
	//copy the solution into the gamestate and SOL_CORRECT for the result
    for (int i = 0; i < 4; i++) {
        gameState->secret.attempt[i] = soluce->attempt[i];
        gameState->secret.result[i] = SOL_CORRECT;
	}
	//initialize history
	for (int j = 0; j < 12; j++) {
		for (int k = 0; k < 4; k++) {
			gameState->history[j].attempt[k] = COLOR_UNDEF;
			gameState->history[j].result[k] = SOL_UNCHECKED;
		}
	}
	return gameState;
}

int checkCombinaison(Gamestate* gameState) {
    if (gameState->turn < 0 || gameState->turn >= 12) {
        return 0; 
    }

    Combo* attempt = &gameState->history[gameState->turn];
    const Combo* solution = &gameState->secret;

    int correctCount = 0;
    int used_in_solution[4] = { 0, 0, 0, 0 };
    int used_in_attempt[4] = { 0, 0, 0, 0 };


    for (int i = 0; i < 4; i++) {
        if (attempt->attempt[i] == solution->attempt[i]) {
            attempt->result[i] = SOL_CORRECT;
            used_in_solution[i] = 1;
            used_in_attempt[i] = 1;
            correctCount++;
        }
        else {
            attempt->result[i] = SOL_UNCHECKED;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (attempt->result[i] == SOL_UNCHECKED) {
            for (int j = 0; j < 4; j++) {
                if (!used_in_solution[j] && !used_in_attempt[i] &&
                    attempt->attempt[i] == solution->attempt[j]) {
                    attempt->result[i] = SOL_PARTIAL;
                    used_in_solution[j] = 1;
                    used_in_attempt[i] = 1;
                    break;
                }
            }
            if (attempt->result[i] == SOL_UNCHECKED) {
                attempt->result[i] = SOL_WRONG;
            }
        }
    }

    return (correctCount == 4);
}