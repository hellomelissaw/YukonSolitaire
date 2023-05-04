//
// Created by Sabirin on 01/05/2023.
//

#include <stdbool.h>

#ifndef YUKONSOLITAIRE_GAMEMOVE_H
#define YUKONSOLITAIRE_GAMEMOVE_H

enum moveType {
    PILE_TO_COL,
    COL_TO_COL,
    COL_TO_FOUND,
    FOUND_TO_COL,
    FOUND_TO_FOUND
};

bool validColumnRange(char in);
bool validFoundationRange(char in);
bool validRank(char in);
bool validSuit(char in);
bool validInputFromTailToFoundation(char* in);
bool validInputFromTailToTail(char* in);
bool validInputFromColumnPileToTail(char* in);
bool validMoveSyntax(char* input, enum moveType *ptr);

#endif //YUKONSOLITAIRE_GAMEMOVE_H
