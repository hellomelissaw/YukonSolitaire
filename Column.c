//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
//#include "LinkedListManipulation.c"
#include <stdio.h>
#define  COLUMN_COUNT 7
#define  ROW_COUNT 11



Card* ptrColumnHead (Card** ptrHead){
    Card* columnPointers[7];

    //for (int k = 0 ; k < COLUMN_COUNT ; k++){


    //}


        for(int i = 0 ; i < ROW_COUNT ;  i++ ){
            for(int j = 0 ; j< COLUMN_COUNT ; j++){
                if (i == 0){
                    columnPointers[0] = createCard((*ptrHead)->rank, (*ptrHead)->suit);
                    (*ptrHead) = (*ptrHead)->next; // move the head to the next card
            }
                else{

                }

        }

    }




    return *columnPointers;
}
