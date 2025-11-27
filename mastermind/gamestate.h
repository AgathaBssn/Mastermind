#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "combo.h"



//4 couleurs et 4 solutions
typedef struct {
    int turn;
    Combo secret;
    Combo history[12];
} Gamestate;



#endif
