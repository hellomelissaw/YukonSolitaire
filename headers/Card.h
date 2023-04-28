//
// Created by Watson on 2023-04-28.
//

#ifndef YUKONSOLITAIRE_CARD_H
#define YUKONSOLITAIRE_CARD_H
#include <stdbool.h>
typedef struct Card
{
    char rank;
    char suit;
    char view[3]; // if the card is unvisible showes [], if visible showes rank and suit
    struct Card *next;
    bool isVisible;

} Card;

Card* createCard(char rank, char suit);
void visibility(Card** cardView, bool visibility);
void setVisibility(Card** currentCards , bool visible);

#endif //YUKONSOLITAIRE_CARD_H
