//
// Created by Watson on 2023-04-16.
//

#ifndef YUKONSOLITAIRE_SHUFFLE_H
#define YUKONSOLITAIRE_SHUFFLE_H
#include <time.h>
#include <stdlib.h>
#include "LinkedListManipulation.h"
#include "Utilities.h"

Card* shuffleInterweave(int split, Card* head);
Card* shuffleRandom(Card* head);

#endif //YUKONSOLITAIRE_SHUFFLE_H
