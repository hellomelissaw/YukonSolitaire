//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Column.c"
int main(void) {
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


    //printDeck(testcard);
    //Card** ptrTestCard = &testcard;
    //Card* columnTest = ptrColumnHead(ptrTestCard);
    //Card* columnTest = ptrColumnHead(&testcard);


    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
    printf("\n");

       /* for (int i = 0 ; i < 11 ; i++){
            //printf("\n");
            for (int j = 0 ; j < 7 ; j++){
                //Card** ptrTestCard = &testcard;
                //Card* columnTest = ptrColumnHead(ptrTestCard);
            //printf("\t%c%c  " , (columnTest)->rank , columnTest->suit);
            //ptrTestCard++;
            //columnTest = columnTest->next;

        }
    }*/
    Card* testcard = createDeck("unshuffledCards.txt");
        Card** ptrTestCard = &testcard;
        Card* gameCollumn = ptrColumnHead(ptrTestCard);
        int printed[7] = {0,0,0,0,0,0,0};

        for (int cardsPrintet = 0; cardsPrintet < 52; cardsPrintet++){
            for(int i = 0; i < 7; i++){
                Card* cardToPrint = gameCollumn;
                for(int j = 0; j < printed[i]; j++){
                    cardToPrint = cardToPrint->next;
                    *cardToPrint++;
                    if(!cardToPrint) break;
                }
                if(!cardToPrint) break;
                printed[i]++;
                printf("\t%c%c ", cardToPrint->rank, cardToPrint->suit);
            }
            printf("\n");
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