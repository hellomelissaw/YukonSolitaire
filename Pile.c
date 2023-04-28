//
// Created by Watson on 2023-04-24.
//
#include <stdlib.h>
#include "Card.c"

typedef struct Pile
{
    Card* head;
    Card* tail;

} Pile;

Pile* createPile() {
    Pile* pile = malloc(sizeof(Pile));
    pile->head = NULL;
    pile->tail = NULL;

    return pile;
}
