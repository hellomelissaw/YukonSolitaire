//
// Created by Sabirin on 28/04/2023.
//


#ifndef YUKONSOLITAIRE_BOARD_H
#define YUKONSOLITAIRE_BOARD_H
#include "Deck.h"
#include "Pile.h"
Pile** setColumnLists (Card* head);
void printBoard(Pile** ptrColumn);
void isVisible (bool isVisible);





#endif //YUKONSOLITAIRE_BOARD_H
