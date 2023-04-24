//
// Created by Watson on 2023-04-24.
//
//#include <ctest.h>
#include <stdio.h>
#include "Board.c"

void moveToFoundatationTest() {
    Card** foundationPiles = setFoundationLists();
    Card* firstCard = createCard('A','C');
    Card** ptrFirstCard = &firstCard;
    bool isValid = validateMoveToFoundation(ptrFirstCard, &foundationPiles[0]);
    if(isValid) {
        insertAtTail(ptrFirstCard, &foundationPiles[0], &foundationPiles[0]);
    }

    printf("The new tail after testing insertion of AC at the start of Foundation pile should be AC. \n The actual card is : %c%c\n", foundationPiles[0]->rank, foundationPiles[0]->suit);


}

