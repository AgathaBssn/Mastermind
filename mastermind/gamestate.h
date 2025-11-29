#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "combo.h"

typedef struct {
    int turn;
    Combo secret;
    Combo history[12];
} Gamestate;

Gamestate* initGameState(Combo* soluce);

int checkCombinaison(Gamestate* gameState);

#endif
