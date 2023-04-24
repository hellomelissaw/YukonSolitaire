//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Board.c"
//#include "moveTests.c"
//#include "pileTest.c"
int main(void) {
    Card* testDeck = createDeck("unshuffledcards.txt");
    Pile** firstColumn = setColumnLists(testDeck);
    printBoard(firstColumn);
    //Card** foundationPiles = setFoundationLists();

    /*for(int i = 0 ; i < 4 ; i++){
        printf("%c%c\n", foundationPiles[i]->rank, foundationPiles[i]->suit);
    }*/

   // moveToFoundatationTest();

   // testAddingAtTailOfPile();

   // testAccessingNextCard();





}