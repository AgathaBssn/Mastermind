#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "combo.h"
#include "display.h"
#include "gamestate.h"
#include "mastermind.h"

int main(void) {
    srand(time(NULL));
    int stillPlaying = 0;

    stillPlaying = askToPlay();

    if (stillPlaying) {
        //init the game
        // //TODO call init a game
        //init player combo to guess
        Combo secret = {
        { COLOR_UNDEF, COLOR_UNDEF, COLOR_UNDEF, COLOR_UNDEF },
        { SOL_UNCHECKED, SOL_UNCHECKED, SOL_UNCHECKED, SOL_UNCHECKED }
        };

        //generate the solution
        initGame(&secret);

        //add the solution to the game state
        Gamestate *currentGameState = initGameState(&secret);

        //launch turns with gameloop
		turn(currentGameState);
        //free the gamestate
		free(currentGameState);

       
    }
    sayBye();

    return 0;
}
