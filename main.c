#include <stdio.h>
#include <string.h>
#include "Deck.c"
int main() {
//saveDeck();
//loadDeck();
    //createDeck("cards.txt");
    printDeck(shuffleInterweave(13,createDeck("cards.txt")));

}
