//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Column.c"
int main(void) {

    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
    printf("\n");
    Card *unshuffledDeck = createDeck("unshuffledCards.txt");
    Card **ptrTestCard = &unshuffledDeck;
    Card **columnTest = ptrColumnHead("unshuffledCards.txt");
    //printf("\t%c%c\t " , (*columnTest[0]).rank , (*columnTest[0]).suit);
    //printf("\t%c%c\t  " , (*columnTest[1]).rank , (*columnTest[1]).suit);
    //printf("\t%c%c\t  " , (*columnTest[2]).rank , (*columnTest[2]).suit);
    //("\t%c%c\t  ", (*columnTest[3]).rank, (*columnTest[3]).suit);
    //printf("\t%c%c\t  " , (*columnTest[4]).rank , (*columnTest[4]).suit);
    //printf("\t%c%c\t  " , (*columnTest[5]).rank , (*columnTest[5]).suit);
    //printf("\t%c%c\t  " , (*columnTest[6]).rank , (*columnTest[6]).suit);

    for (int i = 0; i < 1; i++) {
        //printf("\n");
        for (int j = 0; j < 7; j++) {

            //   printf("\t%c%c \t%c%c  " , (*columnTest[j]).rank , (*columnTest[j]).suit);
            // printf("\t%c%c  " , (*columnTest[j]).rank , (*columnTest[j]).suit);
            //ptrTestCard++;
            //columnTest = columnTest[j]->next;

        }
    }

}