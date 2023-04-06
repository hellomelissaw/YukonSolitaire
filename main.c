#include "Deck.c"
int main() {

    //createDeck("cards.txt");
    printDeck(shuffleInterweave(13,createDeck("cards.txt")));

}
