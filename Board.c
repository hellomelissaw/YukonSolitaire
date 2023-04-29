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
    //void printBoardOLD(char fileName[]) {
    Pile** columns = setColumnLists(head);
    Card *currentCards[COLUMN_COUNT];
    /*currentCards[0] = columns[0]->head;
    currentCards[1] = columns[1]->head;
    currentCards[2] = columns[2]->head;
    currentCards[3] = columns[3]->head;
    currentCards[4] = columns[4]->head;
    currentCards[5] = columns[5]->head;
    currentCards[6] = columns[6]->head;*/


    // creates an array of Card pointers out of each column Pile head Card
    // in order to keep track of which row we're printing
    for (int i = 0; i < COLUMN_COUNT; i++)
        currentCards[i] = columns[i]->head;

    printf("current card column %d is %s \n", 1, currentCards[0]->view);
    printf("current card column %d is %s \n", 2, currentCards[1]->view);
    printf("current card column %d is %s \n", 3, currentCards[2]->view);
    printf("current card column %d is %s \n", 4, currentCards[3]->view);
    printf("current card column %d is %s \n", 5, currentCards[4]->view);
    printf("current card column %d is %s \n", 6, currentCards[5]->view);
    printf("current card column %d is %s \n", 7, currentCards[6]->view);

         printf("\tC1   \t\tC2 \t\tC3  \t\tC4  \t\tC5  \t\tC6  \t\tC7\n");
         int hiddenCounter = 1;
         for (int i = 0; i < ROW_COUNT; i++) {
             for (int j = 0; j < COLUMN_COUNT; j++) {
                 Card *current = currentCards[j];
                 //currentColumn[1].isVisible = true;
                 if (current == NULL) {
                 //if (currentColumn == NULL) {
                     printf("\t\t"); // if there is no card in the current column, make a tab space
                 }
                 else {

                     if(j < hiddenCounter) { // checks whether card should be visible or not
                         setVisibility(&current, true);
                     } else {
                         setVisibility(&current, false);
                     }
                    // setVisibility(&currentCards[j], false);
                     printf("\t%s\t", current->view);
                     currentCards[j] = current->next;

                 }

             }
             hiddenCounter++;
             printf("\n");
         }
     }

    /*Card *currentCardInColumn[COLUMN_COUNT]; // array of Cards that are column heads

    for (int i = 0; i < COLUMN_COUNT; i++) { // Sets each card of array to be the head of their respective column piles
        //setVisibility(&ptrColumn[i]->head, true);
        printf("pointer to pointer #%d is %p \n", i, ptrColumn[i]->head);
        currentCardInColumn[i] = ptrColumn[i]->head;
    }
    printf("\tC1  \t\tC2 \t\tC3  \t\tC4  \t\tC5  \t\tC6  \t\tC7\n");
    int hiddenCounter = 1;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            Card *currentCard = currentCardInColumn[j];
            if (currentCard == NULL) {
                printf("\t\t"); // if there is no card in the current column, make a tab space
            } else {
                // } else {
                //if (i == 0 && j == 0){
                if (j < hiddenCounter) { // checks whether card should be visible or not
                    setVisibility(&currentCard, true);
                } else {
                    setVisibility(&currentCard, false);
                }
                printf("\t%s\t", currentCard->view);
                currentCardInColumn[j] = currentCard->next; // the current columns pointer should point to the next card in the pågældende linked list

            }

        }
        hiddenCounter++;
        printf("\n");
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

*/


