//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Board.c"
//#include "moveTests.c"
//#include "pileTest.c"
int main(void) {
    // TEST CREATION OF COLUMNS
    /*Card* testDeck = createDeck("unshuffledcards.txt");
    Pile** firstColumn = setColumnLists(testDeck);
    printBoard(firstColumn);*/

    //TEST CREATION OF FOUNDATION PILES

    Pile** foundationPiles = setFoundationLists();
    printFoundationLists(foundationPiles);
    Card* ac = createCard('A', 'C');
    if(validateMoveToFoundation(&ac, &foundationPiles[0]->tail)) {
        insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

    printFoundationLists(foundationPiles);


   // moveToFoundatationTest();

   // testAddingAtTailOfPile();

   // testAccessingNextCard();





}