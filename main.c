//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/AllHeaders.h"

// Hey girl hey
int main() {

    //Card *testDeck = load_DefaultDeckLDCommand(NULL);

    ///////////////////////////////////////////////////////////////////////////////
    // TEST CREATION OF COLUMNS
    ///////////////////////////////////////////////////////////////////////////////

    /*Pile **firstColumn = setColumnLists(testDeck);
    Pile **foundations = setFoundationLists();
    printBoard(firstColumn, foundations);*/

    //////////////////////
    // TEST MOVING CARDS
    //////////////////////
    //testInsertAtHeadInsertAtTail();

    //testValidationMovingTenToNine();

    //moveFirstCardToFoundationTest();

    //move2CToFoundationTest();

    // testMove2CAnd3CToColumnWithAS();


    //////////////////////
    // SHUFFLING DECK
    //////////////////////
    //testShuffleRandom5Cards(5);

    /////////////////////////////////
    // VALIDATION FUNCTION TESTS
    /////////////////////////////////
    //testEdgeCaseInputsValidColumnRange();
    //testEdgeCasesValidFoundationRange();
    //testValidRank();
    testValidSuit();

}