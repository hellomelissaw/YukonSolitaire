//
// Created by Mélissa on 2023-04-03.
// ressources : https://www.w3schools.com/c/c_files_read.php

#include <stdlib.h>
#include <stdio.h>
#define CARD_COUNT 52
#define LABEL_SIZE 4
//----------------------------------------------------------
// Setting up Linked Lists for the deck and shuffle piles
//----------------------------------------------------------

struct card
{
    char rank;
    char suit;
    struct card *next;

};

/*const char* CARD_LABELS[CARD_COUNT] = {
        "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC",
        "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD",
        "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH",
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS"
};*/

/*char** loadCardLabels(char fileName[]) {
    char** cardLabels = NULL;
    FILE* fpointer = fopen(fileName, "r"); // creates a pointer to the read file

    char cardLabel[LABEL_SIZE];
    for(int i = 0 ; i < CARD_COUNT ; i++) {
        fgets(cardLabel, LABEL_SIZE, fpointer);
        cardLabels[i] = malloc(LABEL_SIZE);
        cardLabels[i] = cardLabel;
    }
    fclose(fpointer);

    fprintf("%s", cardLabels[0]);

   return cardLabels;
}*/

// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
struct card* createCard(char rank, char suit) {
    struct card* card_node = malloc(sizeof(struct card));
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}

// FUNCTION TO CREATE A DECK ONE CARD AT A TIME USING createCard()
struct card* createDeck(char fileName[]) {
    /* Load card labels from file */
    FILE* fpointer = fopen(fileName, "r"); // creates a pointer to the read file
    char cardLabels[CARD_COUNT][LABEL_SIZE];

    for (int i = 0 ; i < CARD_COUNT ; i++) {
        fgets(cardLabels[i], LABEL_SIZE, fpointer); // gets line i of txt file and populates the char array in cardLabels[i]
    }
    fclose(fpointer);


   /* for (int j = 0 ; j < CARD_COUNT ; j++) {
        printf("For card #%d, rank is %c and its suit is %c\n", j, (char)cardLabels[j][0], (char)cardLabels[j][1]);
    }*/

   /* Add values from the cardLabels array to the array of cards */
    //struct card* cards[CARD_COUNT]; // make a pointer to array of cards
    struct card* head = createCard(cardLabels[0][0], cardLabels[0][1]);
    struct card* current = head;
    for(int i = 1 ; i < CARD_COUNT ; i ++) // get the rank and suit from line i of the file and pass as argument to createCard func
    {
        char rank = cardLabels[i][0];
        char suit = cardLabels[i][1];
        //cards[i] = createCard(rank, suit);
        current->next = createCard(rank, suit);
        current = current->next;
       /* if(i > 0) {
            cards[i-1]->next = cards[i];
        }*/

    }

    /* Add the first card's next card and make it head of Linked List
    cards[0]->next = cards[1];
    struct card *head = cards[0];
     */

   /* Test printing all cards in linked list
    int k = 0;
    current = head;
    while(current != NULL) {
        printf("Card #%d is %c%c\n", k, current->rank, current->suit);
        current = current->next;
        k++;
    }*/

    return head;
}


// FUNCTION INTERWEAVE-SHUFFLE A DECK (BRIDGE SHUFFLE)
int shuffleInterweave(int split, struct card* head) {
    struct card* tempHead1 = NULL;
    struct card* current = NULL;
    tempHead1 = (struct card*) malloc(sizeof(struct card));
    tempHead1->rank = head->rank;
    tempHead1->suit = head->suit;

    current = tempHead1;
    int i = 1;
    while(i < split && head->next != NULL) {
        current->next = createCard(head->next->rank, head->next->suit);
        current = current->next;
        head = head->next;
        i++;
    }

    struct card* current1 = tempHead1;
    while(current1 != NULL) {
        printf("Card in pile 1 is %c%c\n", current1->rank, current1->suit);
        current1 = current1->next;
    }


    struct card* tempHead2 = NULL;
    head = head->next;
    tempHead2 = (struct card*) malloc(sizeof(struct card));
    tempHead2->rank = head->rank;
    tempHead2->suit = head->suit;

    current = tempHead2;
    i = 1;
    while(head->next != NULL) {
        current->next = createCard(head->next->rank, head->next->suit);
        current = current->next;
        head = head->next;
        i++;
    }

    struct card* current2 = tempHead2;
    while(current2 != NULL) {
        printf("Card in pile 2 is %c%c\n", current2->rank, current2->suit);
        current2 = current2->next;
    }

    /*struct card* tempHead1 = head;
    struct card* current = tempHead1;
    while(n > 0) {
        current->next = head->next;
        //printf("Card in pile 1 is : %c%c\n", current->next->rank, current->next->suit);
        current = current->next;
        head = head->next;
        n--;
        //printf("split: %d\n", split);
    }

    struct card* current1 = tempHead1;
    while(current1 != NULL) {
        printf("Card in pile 1 is %c%c\n", current1->rank, current1->suit);
        current1 = current1->next;
    }

    struct card* tempHead2 = head;
    current = tempHead2;
    while(head != NULL) {
        current->next = head->next;
        current = current->next;
        head = head->next;
    }

    struct card* shuffledDeckHead = tempHead1;
    shuffledDeckHead->next = tempHead2;
    current = shuffledDeckHead->next;
*/
    /*while(tempHead1 != NULL && tempHead2 != NULL) {
        current->next = tempHead1->next;
        current->next->next = tempHead2->next;
        current = current->next->next;
        tempHead1 = tempHead1->next;
        tempHead2 = tempHead2->next;
        //printf("I made it to this part of the loop!");
    }

    printf("Card 1 is %c%c and card 2 is %c%c", shuffledDeckHead->rank, shuffledDeckHead->suit, shuffledDeckHead->next->rank, shuffledDeckHead->next->suit);
*/
   /* Test print contents of shuffled deck
    current = shuffledDeckHead;
    int ks = 0;
    while(current != NULL){
        printf("Shuffled deck card #%d is : %c%c", ks, current->rank, current->suit);
        current = current->next;
        ks++;
    }*/


    //struct card tempPile1[split];
    //struct card tempPile2[CARD_COUNT-split];
    //struct card shuffledDeck[CARD_COUNT];




    /* splits the deck in two at given split
    for(int i = 0 ; i < CARD_COUNT ; i++){
        if(i < split) {
            tempPile1[i] = *current;
            //printf("Card #%d in pile1 is %c%c\n", i, current->rank, current->suit);
            current = current->next;
        } else {
            tempPile2[i] = *current;
            //printf("Card #%d in pile2 is %c%c\n", i, current->rank, current->suit);
            current = current->next;
        }
    }
*/
    /* interweaves the two temp arrays into the final shuffled deck */
    /* int j = 0;
     while(split >= 0) {
         int pileCounter = 0;
         shuffledDeck[j] = tempPile1[pileCounter];
         shuffledDeck[j+1] = tempPile2[pileCounter];
         j = j + 2;
         pileCounter++;
         split--;
     }*/

    /*
    int smallestPileSize;
    int smallPile;
    if((CARD_COUNT - split) > CARD_COUNT / 2) {
        smallestPileSize = split;
        smallPile = 1;
    } else {
        smallestPileSize = CARD_COUNT - split;
        smallPile = 2;
    }

    int pileCounter = 0;
    for(int j = 0 ; j < CARD_COUNT ; j++) {
        if(smallestPileSize >= 0) {
            shuffledDeck[j] = tempPile1[pileCounter];
            j++;
            shuffledDeck[j] = tempPile2[pileCounter];
            pileCounter++;
            smallestPileSize--;
        } else {
            if(smallPile == 1) {
                shuffledDeck[j] = tempPile2[pileCounter];
            } else {
                shuffledDeck[j] = tempPile1[pileCounter];
            }
            pileCounter++;
        }
    }

   */

   return 0;
}
