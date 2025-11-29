
#pragma once
#ifndef MASTERMIND_H
#define MASTERMIND_H


#include "combo.h"
#include "gamestate.h"

//Start the game, generate the solution to guess
//@returns 1 if an error occurs, 0 else
int initGame(Combo* soluce);

//Process a turn of the game
//@param the current game state
//@returns the status of the turn 1 win, 0 false
int turn(Gamestate* gameState);

//ask the player its guess
//@returns the combinaison
Combo* getPlayerGuess(void);

#endif