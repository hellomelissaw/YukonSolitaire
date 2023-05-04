//
// Created by Bruger on 4/17/2023.
//
#include <stdlib.h>
#include "headers/AllHeaders.h"
#include <stdio.h>
#ifdef _WIN32 // for Windows
#define CHAR_FORMAT_SPECIFIER "%d"
#endif
#define  COLUMN_COUNT 7
#define  ROW_COUNT 11
#define FOUNDATION_COUNT 4


/// SETS UP THE FOUR PILES REPRESENTING THE FOUNDATION PILES
/// \return pointer to the Pile array
/// SETS UP THE FOUR PILES REPRESENTING THE FOUNDATION PILES
/// \return pointer to the Pile array
Pile** setFoundationLists() {
    Pile** foundations = malloc(4 * sizeof(Pile*));

    for (int i = 0 ; i < FOUNDATION_COUNT ; i++) {
        foundations[i] = createPile(FOUNDATION);

    }

    return foundations;

}

/// SETS THE LINKED LISTS REPRESENTING THE 7 COLUMNS AT THE START OF THE GAME
/// \param head pointer to the head of the deck to load onto the board
/// \return pointer to the array of Pile pointers
Pile** setColumnLists (Card* head) {
    Card** ptrHead = &head;
    Pile** columns = malloc(7 * sizeof(Pile*));

    for (int i = 0 ; i < COLUMN_COUNT ; i++)
        columns[i] = createPile(COLUMN);

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

void printBoard(Pile **columnsFilled, Pile **foundationsBlank) {
    Pile **columns = columnsFilled;
    Card *currentCards[COLUMN_COUNT];

    Pile **foundations = foundationsBlank;
    Card *foundationTop[FOUNDATION_COUNT];
    int counterFoundation = 0;

    // creates an array of Card pointers out of each column Pile head Card
    // in order to keep track of which row we're printing
    for (int i = 0; i < COLUMN_COUNT; i++) {
        currentCards[i] = columns[i]->head;
        if (i < FOUNDATION_COUNT)
            foundationTop[i] = foundations[i]->tail;

    }

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");

    //int offset;
    //int currentFoundation = 1;
    int hiddenCounter = 1;
    for (int i = 0; i < ROW_COUNT; i++) {
        /*
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
         */

        for (int j = 0; j < COLUMN_COUNT; j++) {
        //for (int j = 0; j < COLUMN_COUNT + offset; j++) {
            /*if (j > COLUMN_COUNT - 1) {
                printf("\t[]\tF%d", counterFoundation);
                //currentColumns[j] = currentColumn->next
                counterFoundation++;
                */

                Card *current = currentCards[j];
                if (current == NULL) {
                    printf("\t"); // if there is no card in the current column, for the current row, make a tab space

                } else {
                    if (j >= hiddenCounter)
                        setVisibility(&currentCards[j], false);

                    printf("%s\t", current->view);

                    currentCards[j] = current->next;

                }

            }
            //int rowNumber = i%2;
            if (i % 2 == 0 && counterFoundation < FOUNDATION_COUNT) {
                if (foundationTop[counterFoundation] == NULL) {
                    printf("[]\tF%d", counterFoundation + 1);
                } else {
                    printf("%s\tF%d", foundationTop[counterFoundation]->view, counterFoundation + 1);
                }
                counterFoundation++;

            }

            hiddenCounter++;
            printf("\n");
        }

    }
