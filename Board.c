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
void printBoard(Pile** ptrColumn) {
    Pile *currentColumns[COLUMN_COUNT];

    for (int i = 0; i < COLUMN_COUNT; i++) { // creates an array of pointers to the head card of each of the 7 linked lists representing the columns
        currentColumns[i] = ptrColumn[i];
    }
    printf("\tC1  \t\tC2 \t\tC3  \t\tC4  \t\tC5  \t\tC6  \t\tC7\n");
    int hiddenCounter = 1;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            Pile *currentColumn = currentColumns[j]->head;
            if (currentColumn == NULL) {
                printf("\t\t"); // if there is no card in the current column, make a tab space
            } else {
                // } else {
                //if (i == 0 && j == 0){
                if (j < hiddenCounter) { // checks whether card should be visible or not
                    setVisibility(&currentColumn, true);
                } else {
                    setVisibility(&currentColumn, false);
                }
                printf("\t%s\t", currentColumn->head->view);
                currentColumns[j]->head = currentColumn->head->next;

            }

        }
        hiddenCounter++;
        printf("\n");
    }
}

void isVisible (bool isVisible){
    if (isVisible == true){
        printf("[]");
    }
}

/// FUNCTION USED IN TESTING FOUNDATION PILE CREATION
/// \param foundations pointer to a pointer, pointing to array of piles representing the foundation piles
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

            }
        }
        printf("\n");

}




/*
 * if (currentColumn[i].rank == '2' && currentColumn[i].suit == 'c'){
                    printf("[]");
                }
 */