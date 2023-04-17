//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
//#include "LinkedListManipulation.c"
#include <stdio.h>
#define  COLUMN_COUNT 7
#define  ROW_COUNT 11



Card* ptrColumnHead (Card** ptrHead) {
    Card *columnPointers[7];
    int visibleCounter = 5;
    int visibleCards = 1;
    int columnCounter = 7;
    int rowCounter = 11;

    columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
    (*ptrHead) = (*ptrHead)->next; // move the head to the next card

    for (int i = 1; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            //if (i == 0 && j == 0){
            columnPointers[i] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
            (*ptrHead) = (*ptrHead)->next; // move the head to the next card
        }
        /* else{
             while (visibleCounter < 6){
                 columnPointers[i] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                 (*ptrHead) = (*ptrHead)->next; // move the head to the next card
                 visibleCounter++ ;
             }

         }

 }*/

        // }

        /* for(int i = 0 ; i < ROW_COUNT ;  i++ ){
             if (columnCounter > 1 ){
                 //if (i == 0 && j == 0){
                 columnPointers[i] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                 (*ptrHead) = (*ptrHead)->next; // move the head to the next card
             columnCounter--;
             }

             }*/




        return *columnPointers;
    }
}