//
// Created by Bruger on 4/17/2023.
//
//#include "Deck.c"
#include "Pile.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11
#define FOUNDATION_COUNT 4

Pile** setColumnLists (Card* head) {
    Card** ptrHead = &head;
    Pile** columns = (Pile* []) {createPile(), createPile(), createPile(), createPile(), createPile(), createPile(), createPile()};

    int rowStart[] = {0, 1, 1, 1, 1,1 ,2, 3, 4, 5, 6};
    int rowStartCounter = 0;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = rowStart[rowStartCounter]; j < COLUMN_COUNT; j++) {

                insertAtTail(ptrHead, &columns[j]->head, &columns[j]->tail);

        }
        rowStartCounter++;
    }

    return columns;

}

Pile** setFoundationLists() {
    Pile** foundations = malloc(4 * sizeof(Pile*));


    for (int i = 0 ; i < FOUNDATION_COUNT ; i++) {
        foundations[i] = createPile();
        Card* blankCard = createCard('[',']');
        Card** ptrBlankCard = &blankCard;
        insertAtTail(ptrBlankCard, &foundations[i]->head, &foundations[i]->tail);

    }

    return foundations;

}

void printBoard(Pile** columnTest) {
    Pile* currentColumns[COLUMN_COUNT];

    for (int i = 0; i < COLUMN_COUNT; i++) { // creates an array of pointers to the head card of each of the 7 linked lists representing the columns
        currentColumns[i] = columnTest[i];
    }

    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7\n");
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            Card *currentColumn = currentColumns[j]->head;
            if (currentColumn == NULL) {
                printf("\t\t"); // if there is no card in the current column, make a tab space
            } else {
                printf("\t%c%c\t", currentColumn->rank, currentColumn->suit);
                currentColumns[j]->head = currentColumn->next; // the current columns pointer should point to the next card in the pågældende linked list
            }
        }
        printf("\n");
    }

    printf("");
    printf("LAST command; \n"); //add func
    printf("Message \n"); //add func
    printf("INPUT >");
}

void printFoundationLists(Pile** foundations) {
    Pile* currentFoundation[FOUNDATION_COUNT];

    for (int i = 0; i < FOUNDATION_COUNT; i++) { // creates an array of pointers to the head card of each of the 7 linked lists representing the columns
        currentFoundation[i] = foundations[i];
    }

        for (int j = 0; j < FOUNDATION_COUNT; j++) {
            Card *currentFoundationCard = currentFoundation[j]->tail;
            if (currentFoundationCard == NULL) {
                printf("\t\t"); // if there is no card in the current column, make a tab space
            } else {
                printf("\t%c%c\t\n", currentFoundationCard->rank, currentFoundationCard->suit);
                //currentFoundation[j]->head = currentFoundationCard->next; // the current columns pointer should point to the next card in the pågældende linked list
            }
        }
        printf("\n");

}



