//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Board.c"
int main(void) {
    //printBoard("unshuffledCards.txt");
    Card** foundationPiles = setFoundationLists();

    for(int i = 0 ; i < 4 ; i++){
        printf("%c%c\n", foundationPiles[i]->rank, foundationPiles[i]->suit);
    }

}