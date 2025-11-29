#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "combo.h"
// Represents the current state of the game
// including the turn number, the secret combination,
// and the history of guesses
typedef struct {
    int turn;
    Combo secret;
    Combo history[12];
} Gamestate;

// Initialize the game state with the given solution
//@param soluce pointer to the solution combination
//@returns pointer to the initialized game state
Gamestate* initGameState(Combo* soluce);

// Check the player's current guess against the secret combination
//@param gameState pointer to the current game state
//@returns 1 if the guess is correct, 0 otherwise
int checkCombinaison(Gamestate* gameState);

#endif
