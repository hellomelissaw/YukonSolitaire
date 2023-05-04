//
// Created by Sabirin on 28/04/2023.
//


#ifndef YUKONSOLITAIRE_BOARD_H
#define YUKONSOLITAIRE_BOARD_H
#include "Deck.h"
#include "Pile.h"
Pile** setColumnLists (Card* head);
Pile** setFoundationLists();
void printBoard(Pile **columnsFilled, Pile **foundationsBlank);
void printFoundationLists(Pile** foundations);
void isVisible (bool isVisible);
bool foundationsAreComplete(Pile** foundations);
Pile** setTestFoundations();

#endif //YUKONSOLITAIRE_BOARD_H
