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

void printBoard(char fileName[]) {
    Card **columnTest = setColumnLists(createDeck(fileName));
    Card* currentColumns[COLUMN_COUNT];


    for (int i = 0; i < COLUMN_COUNT; i++) { // creates an array of pointers to the head card of each of the 7 linked lists representing the columns
        currentColumns[i] = columnTest[i];
    }
    printf("\tC1   \t\tC2 \t\tC3  \t\tC4  \t\tC5  \t\tC6  \t\tC7\n");
    int hiddenCounter = 1;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            Card *currentColumn = currentColumns[j];
            //currentColumn[1].isVisible = true;
            if (currentColumn == NULL) {
                printf("\t\t"); // if there is no card in the current column, make a tab space
            }
            else {
                //if (i == 0 && j == 0){
                if(j < hiddenCounter) { // checks whether card should be visible or not
                    setVisibility(&currentColumn, true);
                } else {
                    setVisibility(&currentColumn, false);
                }
                printf("\t%s\t", currentColumn->view);
                currentColumns[j] = currentColumn->next;

                //printf("\t%c%c\t", currentColumn->rank, currentColumn->suit);
                    //currentColumns[j] = currentColumn->next; // the current columns pointer should point to the next card in the pågældende linked list

                    //currentColumns[0]->next = NULL;
                   /* for ( j = 1 ; j < COLUMN_COUNT ; j++)
                    {
                        //setVisibility(&currentColumns[j], false);
                        currentColumns[j]->rank = currentColumn->rank;
                        currentColumns[j]->suit = currentColumn->suit;
                        //setVisibility(currentColumns[j], false);
                        //currentColumn->rank;
                        //currentColumn->suit;
                        //printf("\t[]\t");
                        currentColumns[j] = currentColumn->next;
                        //printf("\t[]\t");

                    }


                //}

                else {
                    setVisibility(currentColumns[1], false);
                    if ( i == 0 && currentColumn != NULL){
                        for ( j = 1 ; j < COLUMN_COUNT ; j++)
                            printf("\t[]\t");
                        currentColumns[j] = currentColumn->next;
                        //currentColumns[j] = currentColumn->next;
                    }

                }

                if (i == 1 && j == 1){
                    printf("\t%c%c\t", currentColumn->rank, currentColumn->suit);
                    currentColumns[j] = currentColumn->next;
                } else{
                    setVisibility(currentColumns[2], false);
                    if ( i == 1 ){
                        for ( j = 2 ; j < COLUMN_COUNT ; j++)
                            printf("\t[]\t");
                        currentColumns[j] = currentColumn->next;
                        //currentColumns[j] = currentColumn->next;
                    }
                }*/
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

/*
 * if (currentColumn[i].rank == '2' && currentColumn[i].suit == 'c'){
                    printf("[]");
                }
 */