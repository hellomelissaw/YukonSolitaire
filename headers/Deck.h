//
// Created by Watson on 2023-04-28.
//

#ifndef YUKONSOLITAIRE_DECK_H
#define YUKONSOLITAIRE_DECK_H
#include "Card.h"
#include "Pile.h"
Card* createDeck(char fileName[]);
int printDeck(Card* head);
void saveDeck(Pile **columnsFilled);
#endif //YUKONSOLITAIRE_DECK_H
