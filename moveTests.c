//
// Created by Watson on 2023-04-24.
//
//#include <ctest.h>
#include <stdio.h>
#include "Board.c"

void moveFirstCardToFoundatationTest() {

    Pile** foundationPiles = setFoundationLists();
    printFoundationLists(foundationPiles);
    Card* ac = createCard('A', 'C');
    if(validateMoveToFoundation(&ac, &foundationPiles[0]->tail)) {
        insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

    printFoundationLists(foundationPiles);

    printf("The new tail after testing insertion of AC at the start of Foundation pile should be AC. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);


}


void move2CToFoundatationTest() {

    Pile** foundationPiles = setFoundationLists();
    printFoundationLists(foundationPiles);
    Card* ac = createCard('A', 'C');
    Card* twoc = createCard('2', 'C');
    if(validateMoveToFoundation(&ac, &foundationPiles[0]->tail)) {
        insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }
    if(validateMoveToFoundation(&twoc, &foundationPiles[0]->tail)) {
        insertAtTail(&twoc, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

    printf("The new tail after testing insertion of AC at the start of Foundation pile should be AC. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);
    printf("The new tail after testing insertion of 2C after AC should be 2C. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);


}

void move3CToFoundatationTest() {

    Pile** foundationPiles = setFoundationLists();
    printFoundationLists(foundationPiles);
    Card* ac = createCard('A', 'C');
    Card* twoc = createCard('2', 'C');
    Card* threec = createCard('3', 'C');
    if(validateMoveToFoundation(&ac, &foundationPiles[0]->tail)) {
        insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }
    if(validateMoveToFoundation(&twoc, &foundationPiles[0]->tail)) {
        insertAtTail(&twoc, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }
    if(validateMoveToFoundation(&threec, &foundationPiles[0]->tail)) {
        insertAtTail(&threec, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

   // printf("The new tail after testing insertion of AC at the start of Foundation pile should be AC. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);
    //printf("The new tail after testing insertion of 2C after AC should be 2C. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);
    printf("The new tail after testing insertion of 3C after 2C should be 3C. \n The actual card is : %c%c\n", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);


}

void testMove2Cn3CToColumnWithAS(){
    Card* as = createCard('A', 'S');
    Card* ac = createCard('A', 'C');
    Card* twoc = createCard('2', 'C');
    Card* threec = createCard('3', 'C');
    Pile* testColumn1 = createPile(as);
    Pile* testColumn2 = createPile(ac);
    insertAtTail(&twoc, &testColumn2->head, &testColumn2->tail);
    insertAtTail(&threec, &testColumn2->head, &testColumn2->tail);
    printf("testColumn2 tail before move expected 3C, actual : %c%c\n", testColumn2->tail->rank, testColumn2->tail->suit);

    moveToColumn(&testColumn2, &testColumn1, '2');
    printf("column1 new tail expected: 3C, actual: %c%c\n", testColumn1->tail->rank, testColumn1->tail->suit);
    printf("testColumn1 tail after move expected AC, actual : %c%c\n", testColumn1->tail->rank, testColumn1->tail->suit);

}




