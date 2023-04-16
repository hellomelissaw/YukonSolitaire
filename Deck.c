//
// Created by Watson on 2023-04-15.
//
#include <stdlib.h>
#include <stdio.h>
#include "Card.c"
#include "Utilities.c"
#define CARD_COUNT 52
#define LABEL_SIZE 4

// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
Card* createCard(char rank, char suit) {
    Card* card_node = malloc(sizeof(Card));
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}

// FUNCTION TO CREATE A DECK ONE CARD AT A TIME USING createCard()
Card* createDeck(char fileName[]) {
    char* abs_path = getAbs_path(fileName);

    /* Load Card labels from file */
    FILE* fpointer = fopen(abs_path, "r"); // creates a pointer to the read file
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

// FUNCTION TO PRINT DECK IN CONSOLE
int printDeck(Card* head) {
    Card* current = head;
    int i = 0;
    while (current != NULL){
        printf("Card #%d: %c%c\n", i, current->rank, current->suit);
        current = current->next;
        i++;
    }
    return 0;
}
