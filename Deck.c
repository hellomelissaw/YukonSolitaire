//
// Created by Mélissa on 2023-04-03.
// ressources : https://www.w3schools.com/c/c_files_read.php

# include <stdlib.h>
# include <stdio.h>
#define CARD_COUNT 52
//----------------------------------------------------------
// Setting up Linked Lists for the deck and shuffle piles
//----------------------------------------------------------

struct card
{
    char rank;
    char suit;

};

const char* CARD_LABELS[CARD_COUNT] = {
        "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC",
        "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD",
        "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH",
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS"
};

// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
struct card* createCard(char rank, char suit) {
    struct card* card_node = malloc(sizeof(struct card));
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}

// FUNCTION TO CREATE A DECK ONE CARD AT A TIME USING createCard()
int createDeck() {
    struct card* cards[CARD_COUNT]; // make array of cards

    for(int i = 0 ; i < CARD_COUNT ; i ++)
    {
        char rank = CARD_LABELS[i][0];
        char suit = CARD_LABELS[i][1];
        cards[i] = createCard(rank, suit);

    }


    for(int i = 0 ; i < 52 ; i ++)
    {
        printf("Card #%d is %c%c\n", i, cards[i]->rank, cards[i]->suit);

    }

    return 0;
}




int saveDeck() {
    FILE * fpointer = fopen("newDeck2.txt", "w");

    fprintf(fpointer, "AC\n"
                      "2C\n"
                      "3C\n"
                      "4C\n"
                      "5C\n"
                      "6C\n"
                      "7C\n"
                      "8C\n"
                      "9C\n"
                      "TC\n"
                      "JC\n"
                      "QC\n"
                      "KC\n"
                      "AD\n"
                      "2D\n"
                      "3D\n"
                      "4D\n"
                      "5D\n"
                      "6D\n"
                      "7D\n"
                      "8D\n"
                      "9D\n"
                      "TD\n"
                      "JD\n"
                      "QD\n"
                      "KD\n"
                      "AH\n"
                      "2H\n"
                      "3H\n"
                      "4H\n"
                      "5H\n"
                      "6H\n"
                      "7H\n"
                      "8H\n"
                      "9H\n"
                      "TH\n"
                      "JH\n"
                      "QH\n"
                      "KH\n"
                      "AS\n"
                      "2S\n"
                      "3S\n"
                      "4S\n"
                      "5S\n"
                      "6S\n"
                      "7S\n"
                      "8S\n"
                      "9S\n"
                      "TS\n"
                      "JS\n"
                      "QS\n"
                      "KS");
    fclose(fpointer);
    return 0;
}

/*int loadDeck() {
    char card[2];
    FILE * fpointer = fopen("newDeck2.txt", "r");
    fgets(card, 2, fpointer);
    fclose(fpointer);
    return 0;
}*/

int shuffleInterweave() {
    // OPEN A FILE USING READ-MODE "r"
    FILE * fpointer = fopen("newDeck2.txt", "r");

    // STORE CONTENTS OF THE FILE IN A STRING
    char cards[157];

    // READ CONTENTS OF FILE (1ST PARAM IS DEST, 2ND MAX DATA SIZE, POINTER TO FILE TO BE READ)
    fgets(cards, 157, fpointer);

    printf("%s",cards);

    fclose(fpointer);
}
