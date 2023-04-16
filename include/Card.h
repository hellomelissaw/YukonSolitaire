//
// Created by Watson on 2023-04-16.
//

#ifndef YUKONSOLITAIRE_CARD_H
#define YUKONSOLITAIRE_CARD_H
#include <stdbool.h>

typedef struct Card
{
    char rank;
    char suit;
    struct Card *next;
    bool isVisible;

} Card;
#endif //YUKONSOLITAIRE_CARD_H
