//
// Created by Watson on 2023-04-24.
//
#include <stdlib.h>
#include "Deck.c"

typedef struct Pile
{
    Card* head;
    Card* tail;

} Pile;

Pile* createPile(Card* head) {
    Pile* pile = malloc(sizeof(Pile));
    pile->head = head;
    pile->tail = head;

    return pile;
}
