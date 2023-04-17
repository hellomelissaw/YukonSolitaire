#include "Deck.c"
#include <stdio.h>
#include <string.h>


#include <stdbool.h>

//#include "loadDeck.c"
/*int main() {

    //createDeck("cards.txt");
    printDeck(shuffleInterweave(13,createDeck("cards.txt")));


}
 */
int load_DefaultDeckLDCommand(){
    printf("inden i funk");

    FILE *fp;
    char str[60];

    /* opening file for reading */
    fp = fopen("defaultDeckOfCards", "r");
    if(fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while(fgets(str, 60, fp) != NULL) {
        printf("%s", str);
        //STORE IN LINKEDLIST.
    }
    fclose(fp);
    return 0;

}


int main() {
    char input[2];
    char str[100];
    char result[100];
    int length;

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
        printf("INPUT >" );

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
                load_DefaultDeckLDCommand();

            } else if(length > 1){

                strcpy(result, str+1);

                printf("Result: %s\n", result);
                //load_deck(result);
            }
        }
        return 0;
        }

        if (!strcmp(input, "Q")) {
            //Resetgame();
        }
    }
