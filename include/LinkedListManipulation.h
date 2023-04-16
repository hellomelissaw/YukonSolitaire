//
// Created by Watson on 2023-04-16.
//

#ifndef YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
#define YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
#include "Card.h"

void insertAtTail(Card** ptrShuffledHead, Card** ptrshuffledTail, Card** ptrUnshuffledHead);

void insertAtHead(Card** ptrShuffledHead, Card** ptrUnshuffledHead);

void insertBetween(Card** ptrShuffledHead, Card** ptrshuffledTail, Card** ptrUnshuffledHead, int numNodesToTraverse);

#endif //YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
