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

/// SETS UP THE FOUR PILES REPRESENTING THE FOUNDATION PILES
/// \return pointer to the Pile array
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

/// PRINTS THE BOARD WITH LINKED LISTS FOR COLUMNS (WIP, to do: print foundation piles)
/// \param ptrColumn
void printBoard(Card *head) {
    Pile** columns = setColumnLists(head);
    Card *currentCards[COLUMN_COUNT];

    // creates an array of Card pointers out of each column Pile head Card
    // in order to keep track of which row we're printing
    for (int i = 0; i < COLUMN_COUNT; i++)
        currentCards[i] = columns[i]->head;

    /*printf("current card column %d is %s \n", 1, currentCards[0]->view);
    printf("current card column %d is %s \n", 2, currentCards[1]->view);
    printf("current card column %d is %s \n", 3, currentCards[2]->view);
    printf("current card column %d is %s \n", 4, currentCards[3]->view);
    printf("current card column %d is %s \n", 5, currentCards[4]->view);
    printf("current card column %d is %s \n", 6, currentCards[5]->view);
    printf("current card column %d is %s \n", 7, currentCards[6]->view);*/

         printf("\tC1 \t\tC2 \t\tC3 \t\tC4 \t\tC5 \t\tC6 \t\tC7\n");
         int hiddenCounter = 1;
         for (int i = 0; i < ROW_COUNT; i++) {
             for (int j = 0; j < COLUMN_COUNT; j++) {
                 Card *current = currentCards[j];
                 if (current == NULL) {
                     printf("\t\t"); // if there is no card in the current column, for the current row, make a tab space
                 }
                 else {
                    if(j >= hiddenCounter)
                        setVisibility(&currentCards[j], false);

                     printf("\t%s\t", current->view);
                     currentCards[j] = current->next;

                 }

             }
             hiddenCounter++;
             printf("\n");
         }
     }
