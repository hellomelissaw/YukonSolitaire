//
// Created by Watson on 2023-04-28.
//

#ifndef YUKONSOLITAIRE_PILE_H
#define YUKONSOLITAIRE_PILE_H
#include "Card.h"
enum pileType {
    COLUMN,
    FOUNDATION,
    DECK
};

typedef struct Pile
{
    Card* head;
    Card* tail;
    enum pileType type;

} Pile;

Pile* createPile(enum pileType pt);
#endif //YUKONSOLITAIRE_PILE_H
