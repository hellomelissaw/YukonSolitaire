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
    Pile** columns = (Pile* []) {createPile(NULL), createPile(NULL), createPile(NULL), createPile(NULL), createPile(NULL), createPile(NULL), createPile(NULL)};

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

Card** setFoundationLists() {

    Card **foundationHeads = (Card **) malloc(4 * sizeof(Card *));
    if (foundationHeads == NULL) {
        printf("Failure to allocate memory to foundation heads x__x");
        return NULL;
    }

    Card **foundationTails = (Card **) malloc(4 * sizeof(Card *));
    if (foundationTails == NULL) {
        printf("Failure to allocate memory to foundation tails x__x");
        return NULL;
    }

    for (int i = 0 ; i < FOUNDATION_COUNT ; i++) {

        foundationHeads[i] = NULL;
        foundationTails[i] = NULL;

        Card* blankCard = createCard('[',']');
        Card** ptrBlankCard = &blankCard;
        insertAtTail(ptrBlankCard, &foundationHeads[i], &foundationTails[i]);

    }

    return foundationHeads;

}

void printBoard(Pile** columnTest) {
    //Pile** columnTest = setColumnLists(firstColumn);
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



