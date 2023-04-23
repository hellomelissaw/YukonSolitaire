//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include "Column.c"
int main(void) {

    printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
    printf("\n");

    Card **columnTest = ptrColumnHead(createDeck("unshuffledCards.txt"));
    /*Card* currentColumn = columnTest[6];
    for(int i = 0 ; i < ROW_COUNT ; i++){
        printf("%c%c ->\n", currentColumn->rank, currentColumn->suit);
         currentColumn = currentColumn->next;
    }*/
    Card* currentColumn[7];
    Card* currentColumn_0 = columnTest[0];
    Card* currentColumn_1 = columnTest[1];
    Card* currentColumn_2 = columnTest[2];
    Card* currentColumn_3 = columnTest[3];
    Card* currentColumn_4 = columnTest[4];
    Card* currentColumn_5 = columnTest[5];
    Card* currentColumn_6 = columnTest[6];
    Card* currentColumn_7 = columnTest[7];

    Card* head = NULL;
    Card* current = NULL;
    for (int i = 0 ; i < 7 ; i++) {
        Card *newNode = malloc(sizeof(Card));
        current->rank;
        current->suit;

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }

    }
    printList(currentColumn_0);
    printList(currentColumn_1);
    printList(currentColumn_2);
    printList(currentColumn_3);
    printList(currentColumn_4);
    printList(currentColumn_5);
    printList(currentColumn_6);

    /*for(int i = 0 ; i < ROW_COUNT ; i++) {
       // for (int j = 0 ; j < 7 ; j++){
            printf("\t%c%c","\t%c%c", "\t%c%c","\t%c%c","\t%c%c","\t%c%c","\t%c%c",
                   currentColumn[0]->rank, currentColumn[0]->suit,
                   currentColumn[1]->rank, currentColumn[1]->suit,
                   currentColumn[2]->rank, currentColumn[2]->suit,
                   currentColumn[3]->rank, currentColumn[3]->suit,
                   currentColumn[4]->rank, currentColumn[4]->suit,
                   currentColumn[5]->rank, currentColumn[5]->suit,
                   currentColumn[6]->rank, currentColumn[6]->suit);
            currentColumn[0]= currentColumn[0]->next;

       // }

    }

    /*for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("\t\t%c%c \n", currentColumn_1->rank, currentColumn_1->suit);
        currentColumn_1 = currentColumn_1->next;
        //currentColumn_2 = currentColumn_2->next;
    }

    /*for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("\t\t\t%c%c ->\n", currentColumn_2->rank, currentColumn_2->suit);
        currentColumn_2 = currentColumn_2->next;
    }

    /*for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("%c%c ->\n", currentColumn_3->rank, currentColumn_3->suit);
        currentColumn_3 = currentColumn_3->next;
    }

    for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("%c%c ->\n", currentColumn_4->rank, currentColumn_4->suit);
        currentColumn_4 = currentColumn_4->next;
    }

    for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("%c%c ->\n", currentColumn_5->rank, currentColumn_5->suit);
        currentColumn_5 = currentColumn_5->next;
    }

    for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("%c%c ->\n", currentColumn_6->rank, currentColumn_6->suit);
        currentColumn_6 = currentColumn_6->next;
    }

    for(int i = 0 ; i < ROW_COUNT ; i++) {
        printf("%c%c ->\n", currentColumn_7->rank, currentColumn_7->suit);
        currentColumn_7 = currentColumn_7->next;
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


}