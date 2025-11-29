#pragma once
#ifndef SOL_H
#define SOL_H

// each possibles states
typedef enum {
    SOL_UNCHECKED = '?',
    SOL_WRONG = 'X',
    SOL_PARTIAL = '~',
    SOL_CORRECT = 'V'
} Sol;

#endif
