//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Column.c"
int main(void) {

    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
    printf("\n");
    Card *unshuffledDeck = createDeck("unshuffledCards.txt");
    Card **ptrTestCard = &unshuffledDeck;
    Card **columnTest = ptrColumnHead(ptrTestCard);
    for(int i = 0 ; i < ROW_COUNT ; i++){
        printf("%c%c ->\n", columnTest[4]->rank, columnTest[4]->suit);
        columnTest[4] = columnTest[4]->next;
    }

    //printDeck(columnTest[1]);
    //printf("\t%c%c\t " , (*columnTest[0]).rank , (*columnTest[0]).suit);
   /* printf("\t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \n " ,
           (*columnTest[0]).rank , (*columnTest[0]).suit,
           (*columnTest[1]).rank , (*columnTest[1]).suit,
           (*columnTest[2]).rank , (*columnTest[2]).suit,
           (*columnTest[3]).rank , (*columnTest[3]).suit,
           (*columnTest[4]).rank , (*columnTest[4]).suit,
           (*columnTest[5]).rank , (*columnTest[5]).suit,
           (*columnTest[6]).rank , (*columnTest[6]).suit
           );
    printf("\t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t  " ,
           (*columnTest[0]).next->rank , (*columnTest[0]).next->suit,
           (*columnTest[1]).next->rank , (*columnTest[1]).next->suit,
           (*columnTest[2]).next->rank , (*columnTest[2]).next->suit,
           (*columnTest[3]).next->rank , (*columnTest[3]).next->suit,
           (*columnTest[4]).next->rank , (*columnTest[4]).next->suit,
           (*columnTest[5]).next->rank , (*columnTest[5]).next->suit,
           (*columnTest[6]).next->rank , (*columnTest[6]).next->suit
    );
    //printf("\t%c%c\t  " , (*columnTest[2]).rank , (*columnTest[2]).suit);
   // printf("\t%c%c\t  ", (*columnTest[3]).rank, (*columnTest[3]).suit);
    //printf("\t%c%c\t  " , (*columnTest[4]).rank , (*columnTest[4]).suit);
    //printf("\t%c%c\t  " , (*columnTest[5]).rank , (*columnTest[5]).suit);
    //printf("\t%c%c\t  " , (*columnTest[6]).rank , (*columnTest[6]).suit);
*/
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