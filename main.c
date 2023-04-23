//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Board.c"
int main(void) {

    //Card **columnTest = setColumnLists(createDeck("unshuffledCards.txt"));
    printBoard(createDeck("unshuffledCards.txt"));
    /*Card* currentColumn = columnTest[6];
    for(int i = 0 ; i < ROW_COUNT ; i++){
        printf("%c%c ->\n", currentColumn->rank, currentColumn->suit);
         currentColumn = currentColumn->next;
    }*/

   /* printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
    printf("\n");
    printf("                                                           []  \tF1\n");
    printf("                                                           []  \tF2\n");
    printf("                                                           []  \tF3\n");
    printf("                                                           []  \tF4\n");

    printf("");
    printf("LAST command; \n"); //add func
    printf("Message \n"); //add func
    printf("INPUT >");
    //printDeck(columnTest[1]);
    //printf("\t%c%c\t " , (*columnTest[0]).rank , (*columnTest[0]).suit);
    printf("\t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \t%c%c\t \n " ,
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


}