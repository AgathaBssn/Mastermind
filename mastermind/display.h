#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H


void showCombo(const Combo* combo);

//Ask the player if he wants to play
//@returns int 1 if yes 0 if no
int askToPlay();

//Ask the player to input its guess
//@param pointer to the player combo to fill
void askPlayerToGuess(Combo* playerCombo);



//Last word to the player before closed the game
void sayBye();

#endif