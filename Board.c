//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11

Card** setColumnLists (Card* head) {

    Card** ptrHead = &head;
    Card **columnHeads = (Card **) malloc(7 * sizeof(Card *));
    if (columnHeads == NULL) {
        printf("Failure to allocate memory to column heads x__x");
        return NULL;
    }

    Card **columnTails = (Card **) malloc(7 * sizeof(Card *));
    if (columnTails == NULL) {
        printf("Failure to allocate memory to column tails x__x");
        return NULL;
    }

    columnHeads = (Card *[]) {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    columnTails = (Card *[]) {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    int visibleCounter = 5;
    int visibleCards = 1;
    int columnCounter = 7;
    int rowCounter = 11;

    //columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
    int rowStart[] = {0, 1, 1, 1, 1,1 ,2, 3, 4, 5, 6};
    int rowStartCounter = 0;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = rowStart[rowStartCounter]; j < COLUMN_COUNT; j++) {

                insertAtTail(ptrHead, &columnHeads[j], &columnTails[j]);


        }
        rowStartCounter++;
    }

    return columnHeads;

}

void printBoard(Card* deckHead) {
    Card** columns = setColumnLists(deckHead);
    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7\n");
    for(int i = 0 ; i < ROW_COUNT ; i++){
        Card* currentColumn = columns[i];
        printf("                                                           []  \tF1\n");
        //printf("\t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \n " ,);
    }

    printf("                                                           []  \tF2\n");
    printf("                                                           []  \tF3\n");
    printf("                                                           []  \tF4\n");

    printf("");
    printf("LAST command; \n"); //add func
    printf("Message \n"); //add func
    printf("INPUT >");
}



