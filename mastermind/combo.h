#pragma once
#ifndef COMBO_H
#define COMBO_H

#include "colors.h"
#include "sol.h"

//4 couleurs et 4 solutions
typedef struct {
    Color attempt[4];
    Sol   result[4];
} Combo;

void showCombo(const Combo* combo);

#endif
