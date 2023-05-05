//
// Created by Admin on 28/04/2023.
//
#include "Card.h"
#ifndef YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
#define YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H


void insertAtTail(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail);
void insertAtHead(Card **ptr_SrcHead, Card **ptr_DestHead);
void insertBetween(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail, int numNodesToTraverse);
void setNewTail(Pile** columnToModify, Card** newTail);
bool validateMoveToFoundation(Card** cardToBeMoved, Card** foundationTail, char** ptrMessage);
bool validateMoveToColumn(Card *src, Pile **destColumn, char **ptrMessage);
void moveCards(Pile **src, Pile **dest, char cardToBeMovedRank, char cardToBeMovedSuit, char **ptrMessage);
//// a single move
typedef struct Move{
    Pile *src;
    Pile *dest;
    char rank;
    char suit;
    struct Move* prev;
    struct Move* next;
}Move;

//// The linkesd list of moves
typedef struct MoveList{
    Move *head; // points to the first move in the list
    Move *tail; // points to the last move in the list
}MoveList;


Move  *createMove(Pile **src , Pile **dest , char rank , char suit);
void AddMove (Pile **src , Pile **dest , char rank , char suit, MoveList **moveList);
void undoLastMove(MoveList **moveList, char** ptrMessage);
#endif //YUKONSOLITAIRE_LINKEDLISTMANIPULATION_H
