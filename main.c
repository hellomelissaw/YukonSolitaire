#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
int main() {
    printDeck(shuffleRandom(createDeck("unshuffledCards.txt")));
    //printDeck(createDeck("unshuffledCards.txt"));
    //printDeck(shuffleInterweave(13,createDeck("unshuffledCards.txt")));



}

//MAKE LAYOUT FOR PLAYING THE GAME IN TERMINAL.





/*
//struct newNode newNode;
int main() {
    char input[2];
    char load[] = "LD";


    while (1) {

        printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
        printf("\n");
        printf("                                                           []  \tF1\n");
        printf("                                                           []  \tF2\n");
        printf("                                                           []  \tF3\n");
        printf("                                                           []  \tF4\n");

        printf("");
        printf("LAST command; \n");
        printf("Message \n");
        printf("INPUT >");

        scanf("%s", &input);

        //TJEK FOR OM ARG == 0,.

        if (!strcmp(input, "QQ")) {
            printf("quitting the program");
            exit(0);
        }
        if (strcmp(input, "LD")){

        }
        if (strcmp(input, "Q") == 0) {
            //Resetgame();
        }
    }
}
 */