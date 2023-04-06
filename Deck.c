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
    /* create first card in temp card list1 the create all the rest up to split */
    struct card* tempHead1 = NULL;
    struct card* current = NULL;
    struct card* currentHead = NULL;

    tempHead1 = malloc(sizeof(struct card));
    tempHead1->rank = head->rank;
    tempHead1->suit = head->suit;

    current = tempHead1;
    currentHead = head;

    for(int j = 1 ; j < split ; j++){
        current->next = createCard(currentHead->next->rank, currentHead->next->suit);
            current = current->next;
            currentHead = currentHead->next;
    }


    struct card* current1 = tempHead1;
    //printf("Card in pile 1 is %c%c\n", tempHead1->rank, tempHead1->suit);
   while(current1 != NULL) {
        printf("Card in pile 1 is %c%c\n", current1->rank, current1->suit);
        current1 = current1->next;
    }

/*create first card in temp list2 then all the other cards until OG list head reaches NULL */
    struct card* tempHead2 = NULL;

    tempHead2 = malloc(sizeof(struct card));
    currentHead = currentHead->next;
    tempHead2->rank = currentHead->rank;
    tempHead2->suit = currentHead->suit;
    current = tempHead2;
    currentHead = currentHead->next;
    int i = 1;
    while(currentHead != NULL) {
        current->next = createCard(currentHead->rank, currentHead->suit);
        current = current->next;
        currentHead = currentHead->next;
        i++;
    }

    struct card* current2 = tempHead2;
    while(current2 != NULL) {
        printf("Card in pile 2 is %c%c\n", current2->rank, current2->suit);
        current2 = current2->next;
    }

    /*Initializing the two first cards in the shuffled deck*/
    struct card* shuffledDeckHead = head;
    struct card* currentTempHead1 = tempHead1;
    struct card* currentTempHead2 = tempHead2;
    /*printf("cth1 = %c%c, cth1->next = %c%c, cth1->next->next = %c%c, cth1->next->next->next = %c%c, cth1->next->next->next-> = %c%c\n",
           currentTempHead1->rank,currentTempHead1->suit,
           currentTempHead1->next->rank,currentTempHead1->next->suit,
           currentTempHead1->next->next->rank,currentTempHead1->next->next->suit,
           currentTempHead1->next->next->next->rank, currentTempHead1->next->next->next->suit,
           currentTempHead1->next->next->next->next->rank, currentTempHead1->next->next->next->next->suit);

    printf("cth2 = %c%c, cth2->next = %c%c, cth2->next->next = %c%c, cth2->next->next->next = %c , cth2->next->next->next-> = %c \n",
           currentTempHead2->rank,currentTempHead2->suit,
           currentTempHead2->next->rank,currentTempHead2->next->suit,
           currentTempHead2->next->next->rank,currentTempHead2->next->next->suit,
           currentTempHead2->next->next->next->rank,
           currentTempHead2->next->next->next->next->suit
           );*/

    shuffledDeckHead->rank = currentTempHead1->rank;
    shuffledDeckHead->suit = currentTempHead1->suit;
    //shuffledDeckHead->next = head->next;
    if(shuffledDeckHead->next == NULL) {
        printf("IT'S NULL!");
    } else {
        shuffledDeckHead->next->rank = currentTempHead2->rank;
        shuffledDeckHead->next->suit = currentTempHead2->suit;
    }
    printf("card #0 is %c%c\n", shuffledDeckHead->rank, shuffledDeckHead->suit);
    printf("card #1 is %c%c\n", shuffledDeckHead->next->rank, shuffledDeckHead->next->suit);

    current = shuffledDeckHead->next;
    printf("current card after assigning it shuffledeck->next %c%c\n", current->rank, current->suit);

    for(int k = 2; k < CARD_COUNT ; k++) {
        current->next = currentTempHead1;
        currentTempHead1 = currentTempHead1->next;
        //printf("currentTempHead1 after assigning it to the next node: %c%c\n", currentTempHead1->rank, currentTempHead1->suit);

        current->next->next = currentTempHead2;
        currentTempHead2 = currentTempHead2->next;
       // printf("currentTempHead2 after assigning it to the next node: %c%c\n", currentTempHead2->rank, currentTempHead2->suit);

        if(currentTempHead1 == NULL || currentTempHead2 == NULL){
            break;
        }

        current = current->next->next;

    }

   return 0;
}


