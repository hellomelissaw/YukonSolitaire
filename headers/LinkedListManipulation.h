//
// Created by Admin on 28/04/2023.
//
#include "Card.h"
#ifndef YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
#define YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H

void insertAtTail(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail);
void insertAtHead(Card **ptr_SrcHead, Card **ptr_DestHead);
void insertBetween(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail, int numNodesToTraverse);
void setNewTail(Pile** columnToModify, Card* newTail);
bool validateMoveToFoundation(Card** cardToBeMoved, Card** foundationTail, char** ptrMessage);
bool validateMoveToColumn(Card* src, Pile** destColumn);
void moveToColumn(Pile** src, Pile** destColumn, char cardToBeMovedRank);
#endif //YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
