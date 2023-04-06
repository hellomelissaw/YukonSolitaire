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


   /* Add values from the cardLabels array to the array of cards */
    struct card* head = createCard(cardLabels[0][0], cardLabels[0][1]);
    struct card* current = head;
    for(int i = 1 ; i < CARD_COUNT ; i ++) // get the rank and suit from line i of the file and pass as argument to createCard func
    {
        char rank = cardLabels[i][0];
        char suit = cardLabels[i][1];
        current->next = createCard(rank, suit);
        current = current->next;

    }

    return head;
}

int printDeck(struct card* head) {
    struct card* current = head;
    for(int i = 0 ; i < CARD_COUNT ; i++) {
        printf("card #%d: %c%c\n", i, current->rank, current->suit);
        current = current->next;
    }
}

