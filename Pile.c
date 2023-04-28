//
// Created by Watson on 2023-04-24.
//
#include <stdlib.h>
#include "headers/AllHeaders.h"


Pile* createPile() {
    Pile* pile = malloc(sizeof(Pile));
    pile->head = NULL;
    pile->tail = NULL;

    return pile;
}
