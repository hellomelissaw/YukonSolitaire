//
// Created by Mélissa on 2023-04-03.
// ressources : https://www.w3schools.com/c/c_files_read.php
//              https://www.programiz.com/c-programming/c-structures-pointers
//              https://www.programiz.com/dsa/linked-list
//

#include <stdlib.h>
#include <stdio.h>
#include "Card.c"
#define CARD_COUNT 52
#define LABEL_SIZE 4
//----------------------------------------------------------
// Setting up Linked Lists for the deck and shuffle piles
//----------------------------------------------------------

// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
Card* createCard(char rank, char suit) {
    Card* card_node = malloc(sizeof(Card));
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}

// FUNCTION TO CREATE A DECK ONE CARD AT A TIME USING createCard()
Card* createDeck(char fileName[]) {
    /* Load Card labels from file */
    FILE* fpointer = fopen(fileName, "r"); // creates a pointer to the read file
    char cardLabels[CARD_COUNT][LABEL_SIZE];

    for (int i = 0 ; i < CARD_COUNT ; i++) {
        fgets(cardLabels[i], LABEL_SIZE, fpointer); // gets line i of txt file and populates the char array in cardLabels[i]
    }
    fclose(fpointer);


   /* Add values from the cardLabels array to the array of cards */
    Card* head = createCard(cardLabels[0][0], cardLabels[0][1]);
    Card* current = head;
    for(int i = 1 ; i < CARD_COUNT ; i ++) // get the rank and suit from line i of the file and pass as argument to createCard func
    {
        char rank = cardLabels[i][0];
        char suit = cardLabels[i][1];
        current->next = createCard(rank, suit);
        current = current->next;

    }

    return head;
}


// FUNCTION INTERWEAVE-SHUFFLE A DECK (BRIDGE SHUFFLE)
Card* shuffleInterweave(int split, Card* head) {
    /* create first Card in temp Card list1 the create all the rest up to split */
    Card* tempHead1 = NULL;
    Card* current = NULL;
    Card* currentHead = NULL;

    tempHead1 = malloc(sizeof(Card));
    tempHead1->rank = head->rank;
    tempHead1->suit = head->suit;

    current = tempHead1;
    currentHead = head;

    for(int j = 1 ; j < split ; j++){
        current->next = createCard(currentHead->next->rank, currentHead->next->suit);
            current = current->next;
            currentHead = currentHead->next;
    }


/*create first Card in temp list2 then all the other cards until OG list head reaches NULL */
    Card* tempHead2 = NULL;

    tempHead2 = malloc(sizeof(Card));
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

    /*struct Card* current2 = tempHead2;
    while(current2 != NULL) {
        printf("Card in pile 2 is %c%c\n", current2->rank, current2->suit);
        current2 = current2->next;
    }*/

    /*Initializing the two first cards in the shuffled deck*/
    Card* shuffledDeckHead = head;
    Card* currentTempHead1 = tempHead1;
    Card* currentTempHead2 = tempHead2;

    shuffledDeckHead->rank = currentTempHead1->rank;
    shuffledDeckHead->suit = currentTempHead1->suit;

    current = shuffledDeckHead;
    currentTempHead1 = currentTempHead1->next;

    while(currentTempHead1 != NULL && currentTempHead2 != NULL) {
        current->next = currentTempHead2;
        currentTempHead2 = currentTempHead2->next;

        current->next->next = currentTempHead1;
        currentTempHead1 = currentTempHead1->next;
        current = current->next->next;
    }


    if(currentTempHead1 == NULL) {
        while(currentTempHead2 != NULL){
            current->next = currentTempHead2;
            current = current->next;
            currentTempHead2 = currentTempHead2->next;
        }

    } else if (currentTempHead2 == NULL) {
        while(currentTempHead1 != NULL) {
            current->next = currentTempHead1;
            current = current->next;
            currentTempHead1 = currentTempHead1->next;
        }
    }

   return shuffledDeckHead;
}

int printDeck(Card* head) {
    Card* current = head;
    for(int i = 0 ; i < CARD_COUNT ; i++) {
        printf("Card #%d: %c%c\n", i, current->rank, current->suit);
        current = current->next;
    }
    return 0;
}
