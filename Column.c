//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11

/*struct  Card* cardList1 = NULL;
struct  Card* cardList2 = NULL;
struct  Card* cardList3 = NULL;
struct  Card* cardList4 = NULL;
struct  Card* cardList5 = NULL;
struct  Card* cardList6 = NULL;
struct  Card* cardList7 = NULL*/

Card** ptrColumnHead (Card* ptrHead) {


    Card **columnPointers = (Card **) malloc(7 * sizeof(Card *));
    //columnPointers = (Card*) malloc(sizeof(Card) * 7);

    //Card* columnPointers[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    //Card** ptr_columnPointers[7] = {&cardList1, &cardList2, &cardList3, &cardList4, &cardList5, &cardList6, &cardList7};
    int visibleCounter = 5;
    int visibleCards = 1;
    int columnCounter = 7;
    int rowCounter = 11;

    //columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
    //(*ptrHead) = (*ptrHead)->next; // move the head to the next card



    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (i == 0) { // sets all the cards in the first row
                // Card *card = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                insertAtTail(ptrHead, &columnPointers[j], &columnPointers[j]);
                //columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                //(*ptrHead) = (*ptrHead)->next; // move the head to the next card

            }
            if (i > 0) {
                Card *card = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                columnPointers[i] = &card[i];
                //columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                (*ptrHead) = (*ptrHead)->next; // move the head to the next card
            } else {
                // while (visibleCounter < 6){
                //columnPointers[i] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                //(*ptrHead) = (*ptrHead)->next; // move the head to the next card
                // visibleCounter++ ;
                //}

            }

        }

        // }

        for (int i = 0; i < ROW_COUNT; i++) {
            if (columnCounter > 1) {
                //if (i == 0 && j == 0){
                columnPointers[i] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                (*ptrHead) = (*ptrHead)->next; // move the head to the next card
                columnCounter--;
            }

        }

        for (int i = 0; i < COLUMN_COUNT; i++) {

        }

    }
    return ptrHead;

}


