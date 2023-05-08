//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/AllHeaders.h"

// Hey girl hey
int main() {
    //testInsertAtHeadInsertAtTail();
    //testShuffleRandom5Cards(5);

    Card *testDeck = load_DefaultDeckLDCommand(NULL);
    //printDeck(shuffleInterweave(13, createDeck("unshuffledCards.txt")));

    ///////////////////////////////////////////////////////////////////////////////
    // TEST CREATION OF COLUMNS
    ///////////////////////////////////////////////////////////////////////////////

    Pile **firstColumn = setColumnLists(testDeck);
    Pile **foundations = setFoundationLists();
    printBoard(firstColumn, foundations);

    //////////////////////
    // TEST MOVING CARDS
    //////////////////////
   //testValidationMovingTenToNine();

    //moveFirstCardToFoundationTest();

     //move2CToFoundationTest();

    // testMove2CAnd3CToColumnWithAS();


}