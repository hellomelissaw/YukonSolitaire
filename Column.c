//
// Created by Bruger on 4/17/2023.
//
#include "Deck.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

#define  COLUMN_COUNT 7
#define  ROW_COUNT 11

/*struct  Card* cardList1 = NULL;
struct  Card* cardList2 = NULL;
struct  Card* cardList3 = NULL;
struct  Card* cardList4 = NULL;
struct  Card* cardList5 = NULL;
struct  Card* cardList6 = NULL;
struct  Card* cardList7 = NULL*/

Card** ptrColumnHead (Card* head) {

    Card** ptrHead = &head;
    Card **columnHeads = (Card **) malloc(7 * sizeof(Card *));
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
    //(*ptrHead) = (*ptrHead)->next; // move the head to the next card
    int rowStart[] = {0, 1, 1, 1, 1,1 ,2, 3, 4, 5, 6};
    int rowStartCounter = 0;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = rowStart[rowStartCounter]; j < COLUMN_COUNT; j++) {
           // if (i == 0) { // sets all the cards in the first row

                insertAtTail(ptrHead, &columnHeads[j], &columnTails[j]);

           // }

        }
        rowStartCounter++;
    }
    for(int i = 0 ; i < ROW_COUNT ; i++){
        //("%c%c ->\n", columnTest[3]->rank, columnTest[3]->suit);
        //columnTest[3] = columnTest[3]->next;
        //printf("%c%c ->\n", columnHeads[4]->rank, columnHeads[4]->suit);
        //columnHeads[4] = columnHeads[4]->next;
    }
   // Card** ptr = &columnHeads[0];

    return columnHeads;

}




