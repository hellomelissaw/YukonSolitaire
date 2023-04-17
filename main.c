#include "Deck.c"
#include <stdio.h>
#include <string.h>
//#include "loadDeck.c"
/*int main() {

    //createDeck("unshuffledCards.txt");
    printDeck(shuffleInterweave(13,createDeck("unshuffledCards.txt")));


}
 */


int main() {
    char input[2];
    char str[100];
    int length;
    int newlength;

    while (1) {

        printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
        printf("\n");
        printf("                                                           []  \tF1\n");
        printf("                                                           []  \tF2\n");
        printf("                                                           []  \tF3\n");
        printf("                                                           []  \tF4\n");

        printf("");
        printf("LAST command; \n"); //add func
        printf("Message \n"); //add func
        printf("INPUT >");

        scanf("%s", &input);


        if (!strcmp(input, "QQ")) {
            printf("Quitting The Game");
            exit(0);
        }
        if (!strcmp(input, "LD")){
            fgets(str, 100, stdin);
            length = strlen(str);

            printf("Length of |%s| is |%d|\n", str, length);

            if(length == 1){
                printf("LD is entered");

            } else if(length > 1){
                newlength = length-1;
                printf("new string %d",newlength);
            }
        }
        return 0;
            //load_deck("defaultDeckofCards");
        }
        if (!strcmp(input, "Q")) {
            //Resetgame();
        }
    }
