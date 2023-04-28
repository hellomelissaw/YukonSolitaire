//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11

Card **setColumnLists(Card *head) {

    Card **ptrHead = &head;
    Card **columnHeads = (Card **) malloc(7 * sizeof(Card *));
    bool visible;

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
    int rowStart[] = {0, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6};
    int rowStartCounter = 0;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = rowStart[rowStartCounter]; j < COLUMN_COUNT; j++) {

            insertAtTail(ptrHead, &columnHeads[j], &columnTails[j]);
        }
        rowStartCounter++;
    }
    return columnHeads;
}

void printBoard(char fileName[]) {
    Card **columnTest = setColumnLists(createDeck(fileName));
    Card *currentColumns[COLUMN_COUNT];
    int counterFaundation = 1;


    for (int i = 0; i < COLUMN_COUNT; i++) { // creates an array of pointers to the head card of each of the 7 linked lists representing the columns
        currentColumns[i] = columnTest[i];
    }
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    int hiddenCounter = 1;
    int offset;
    for (int i = 0; i < ROW_COUNT; i++) {
        switch (i) {
            case 0:
                offset = 1;
                break;
            case 2:
                offset = 1;
                break;
            case 4:
                offset = 1;
                break;
            case 6:
                offset = 1;
                break;
            default:
                offset = 0;
                break;
        }
        for (int j = 0; j < COLUMN_COUNT + offset; j++) {
            if (j > COLUMN_COUNT-1) {
                printf("\t[]\tF%d",counterFaundation);
                //currentColumns[j] = currentColumn->next
                counterFaundation++;
            } else {
                Card *currentColumn = currentColumns[j];
                if (currentColumn == NULL) {
                    printf("\t"); // if there is no card in the current column, make a tab space
                } else {
                    if (j < hiddenCounter) { // checks whether card should be visible or not
                        setVisibility(&currentColumn, true);
                    } else {
                        setVisibility(&currentColumn, false);
                    }
                    printf("%s\t", currentColumn->view);
                    currentColumns[j] = currentColumn->next;
                }
            }
        }
        hiddenCounter++;
        printf("\n");
    }

    printf("");
    printf("LAST command; \n"); //add func
    printf("Message \n"); //add func
    printf("INPUT >");
}


