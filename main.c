//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Column.c"
int main() {
    //printDeck(shuffleRandom(createDeck("unshuffledCards.txt")));
    //printDeck(createDeck("unshuffledCards.txt"));
    //printDeck(shuffleInterweave(13,createDeck("unshuffledCards.txt")));

    // EXAMPLE OF insertAtHead() function use
    /*Card* card1 = createCard('A','C');
    Card* card2 = createCard('2','C');
    Card* card3 = createCard('3','C');
    Card* card4 = createCard('4','C');
    card1->next = card2;
    card3->next = card4;

    Card** ptrcard1 = &card1;
    Card** ptrcard2 = &card2;
    Card** ptrcard3 = &card3;
    Card** ptrcard4 = &card4;
    insertAtHead(ptrcard1, ptrcard3);

    printf("%c%c\n", card1->rank, card1->suit);
    printf("%c%c\n", card1->next->rank, card1->next->suit);
    printf("%c%c\n", card1->next->next->rank, card1->next->next->suit);*/

    Card* testcard = createDeck("unshuffledCards.txt");
    //printDeck(testcard);
    Card** ptrTestCard = &testcard;
    Card* columnTest = ptrColumnHead(ptrTestCard);
    for (int i = 0 ; i < 7 ; i++){
        printf("%c%c\n" , columnTest->rank , columnTest->suit);
    }





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