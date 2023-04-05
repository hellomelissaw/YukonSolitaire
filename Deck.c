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
    struct card* cards[CARD_COUNT]; // make a pointer to array of cards

    for(int i = 0 ; i < CARD_COUNT ; i ++) // get the rank and suit from line i of the file and pass as argument to createCard func
    {
        char rank = cardLabels[i][0];
        char suit = cardLabels[i][1];
        cards[i] = createCard(rank, suit);

        if(i > 0) {
            cards[i-1]->next = cards[i];
        }

    }

    /* Add the first card's next card and make it head of Linked List */
    cards[0]->next = cards[1];
    struct card *head = cards[0];

    return head;
}


int shuffleInterweave(int split) {
    // OPEN A FILE USING READ-MODE "r"
    FILE * fpointer = fopen("newDeck2.txt", "r");

    // STORE CONTENTS OF THE FILE IN A STRING
    char cards[157];

    // READ CONTENTS OF FILE (1ST PARAM IS DEST, 2ND MAX DATA SIZE, POINTER TO FILE TO BE READ)
    fgets(cards, 157, fpointer);

    printf("%s",cards);

    fclose(fpointer);
}
