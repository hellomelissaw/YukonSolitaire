//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Board.c"
int main(void) {
    //printBoard("unshuffledCards.txt");
    Card** foundationPiles = setFoundationLists();
    printf("%c%c", foundationPiles[0]->rank, foundationPiles[0]->suit);
}