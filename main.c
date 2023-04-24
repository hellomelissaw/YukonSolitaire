#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
//#include "Board.c"
//#include "moveTests.c"
//#include "pileTest.c"
int main(void) {
    // TEST CREATION OF COLUMNS
    /*Card* testDeck = createDeck("unshuffledcards.txt");
    Pile** firstColumn = setColumnLists(testDeck);
    printBoard(firstColumn);*/

  // moveFirstCardToFoundatationTest();

  // move2CToFoundatationTest();

 // move3CToFoundatationTest();

 //testMove2Cn3CToColumnWithAS();

  //  testAccessingNextCard();

    Card* testDeck = createDeck("unshuffledCards.txt");
    //shuffleRandom(testDeck);
    shuffleInterweave(45, testDeck);
    printDeck(testDeck);



}