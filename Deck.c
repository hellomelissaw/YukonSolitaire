//
// Created by Watson on 2023-04-15.
//
#include <stdlib.h>
#include <stdio.h>
#include "headers/AllHeaders.h"
#define CARD_COUNT 52
#define LABEL_SIZE 4

///  FUNCTION TO CREATE A DECK ONE CARD AT A TIME USING createCard()
/// \param fileName name of the file which contains the card labels
/// \return pointer to the head of the newly created Linked List of Card structs
Card* createDeck(char fileName[]) {
    //char* abs_path1 = getAbs_path(fileName);
    char* abs_path = getAbs_path(fileName);
    //char* abs_path = fileName;

    /* Load Card labels from file */
    FILE* fpointer = fopen(abs_path, "rt"); // creates a pointer to the read file
    //FILE* fpointer = fopen(abs_path, "rt"); // creates a pointer to the read file
    char cardLabels[CARD_COUNT][LABEL_SIZE];


    //printf("%s",fileName);
    for (int i = 0 ; i < CARD_COUNT ; i++) {
        fgets(cardLabels[i], LABEL_SIZE, fpointer); // gets line i of txt file and populates the char array in cardLabels[i]
    }
    fclose(fpointer);


    /* Add values from the cardLabels array to the array of cards */
    Pile* newDeck = createPile(DECK);

    for(int i = 0 ; i < CARD_COUNT ; i ++) // get the rank and suit from line i of the file and pass as argument to createCard func
    {
        char rank = cardLabels[i][0];
        char suit = cardLabels[i][1];
        Card* newCard = createCard(rank, suit);
        insertAtTail(&newCard, &newDeck->head, &newDeck->tail);


    }

    return newDeck->head;
}

/// FUNCTION TO PRINT DECK IN CONSOLE
/// \param head pointer to the head of the Linked List of Cards which should be printed in console
/// \return 0
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
