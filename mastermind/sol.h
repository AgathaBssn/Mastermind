#pragma once
#ifndef SOL_H
#define SOL_H

// etat possibles
typedef enum {
    SOL_UNCHECKED = '?',
    SOL_WRONG = 'X',
    SOL_PARTIAL = '~',
    SOL_CORRECT = 'V'
} Sol;

#endif
