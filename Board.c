//
// Created by Bruger on 4/17/2023.
//
#include <stdlib.h>
#include "headers/AllHeaders.h"
#include <stdio.h>

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
    Pile** columns = columnsFilled;
    Card *currentCards[COLUMN_COUNT];

    Pile** foundations = foundationsBlank;
    Card *foundationTop[FOUNDATION_COUNT];
    int counterFoundation = 0;

    // creates an array of Card pointers out of each column Pile head Card
    // in order to keep track of which row we're printing
    for (int i = 0; i < COLUMN_COUNT; i++){
        currentCards[i] = columns[i]->head;
        if(i < FOUNDATION_COUNT)
            foundationTop[i] = foundations[i]->tail;

    }

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");

    int offset;
    //int hiddenCounter = 1;
    for (int i = 0; i < ROW_COUNT; i++) {
        /*    switch (i) {
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
            }*/

        for (int j = 0; j < COLUMN_COUNT; j++) {
        //for (int j = 0; j < COLUMN_COUNT + offset; j++) {
            Card *current = currentCards[j];
                if (current == NULL) {
                    printf("\t"); // if there is no card in the current column, for the current row, make a tab space

                } else {
                  /*  if(j >= hiddenCounter)
                        setVisibility(&currentCards[j], false);*/

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

       // hiddenCounter++;
        printf("\n");
    }

    }

bool foundationsAreComplete(Pile ** foundations) {
    for(int f = 0 ; f < FOUNDATION_COUNT ; f++) {
        if(!(foundations[f]->tail->rank == 'K')){
            return false;
        }
    }
    return true;

}

Pile** setTestFoundations() {
    Pile** foundations = malloc(4 * sizeof(Pile*));

    for (int i = 0 ; i < FOUNDATION_COUNT ; i++) {
        foundations[i] = createPile(FOUNDATION);

    }


    Card * JS = createCard('J', 'S');
    Card * QS = createCard('Q', 'S');

    Card * KC = createCard('K', 'C');
    Card * KD = createCard('K', 'D');
    Card * KH = createCard('K', 'H');

    insertAtTail(&KH, &foundations[0]->head, &foundations[0]->tail);
    insertAtTail(&KC, &foundations[1]->head, &foundations[1]->tail);
    insertAtTail(&KD, &foundations[2]->head, &foundations[2]->tail);
    insertAtTail(&JS, &foundations[3]->head, &foundations[3]->tail);
    insertAtTail(&QS, &foundations[3]->head, &foundations[3]->tail);
    //printf("Fourth foundation pile head: %s and tail: %s",foundations[3]->head->view, foundations[3]->tail->view);
    return foundations;

}




