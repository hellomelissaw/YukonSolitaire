//
// Created by Watson on 2023-04-28.
//

#ifndef YUKONSOLITAIRE_PILE_H
#define YUKONSOLITAIRE_PILE_H
#include "Card.h"
typedef struct Pile
{
    Card* head;
    Card* tail;

} Pile;

Pile* createPile();
#endif //YUKONSOLITAIRE_PILE_H
