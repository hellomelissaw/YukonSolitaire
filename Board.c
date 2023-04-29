//
// Created by Bruger on 4/17/2023.
//
#include <stdlib.h>
#include "headers/AllHeaders.h"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11
#define FOUNDATION_COUNT 4

/// SETS THE LINKED LISTS REPRESENTING THE 7 COLUMNS AT THE START OF THE GAME
/// \param head pointer to the head of the deck to load onto the board
/// \return pointer to the array of Pile pointers
Pile** setColumnLists (Card* head) {
    Card** ptrHead = &head;

    // creating an array of pointers, each pointing to the pointer to a Pile in the array of Piles
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

void printBoard(char fileName[]) {
    Card **columnTest = setColumnLists(createDeck(fileName));
    Card* currentColumns[COLUMN_COUNT];
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


