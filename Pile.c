//
// Created by Watson on 2023-04-24.
//
#include <stdlib.h>
#include "headers/AllHeaders.h"


Pile* createPile(enum pileType pt) {
    Pile* pile = malloc(sizeof(Pile));
    pile->head = NULL;
    pile->tail = NULL;
    pile->type = pt;
    return pile;
}
