//
// Created by Sabirin
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_SUITS 4
#define NUM_CARDS_PER_SUIT 13
#define NUM_CARDS 52


// Arrays to store suit and rank names
char* suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char* ranks[] = {"A", "2", "3", "4", "5", "6", "7",
                 "8", "9", "10", "J", "Q", "K"};


// Struct to represent a card
typedef struct {
    char rank[3];
    char suit[8];
    bool isVisible;
    struct card *next;
} Card;


//struct linkedList
struct linkedList{
    struct node *head;
};


// Array to store the deck of cards
Card deck[NUM_CARDS];


// Function to check if a card is valid
int is_valid_card(char* rank, char* suit) {
    int valid_rank = 0, valid_suit = 0;

    // Check if the rank is valid
    for (int i = 0; i < NUM_CARDS_PER_SUIT; i++) {
        if (strcmp(rank, ranks[i]) == 0) {
            valid_rank = 1;
            break;
        }
    }
    // Check if the suit is valid
    for (int i = 0; i < NUM_SUITS; i++) {
        if (strcmp(suit, suits[i]) == 0) {
            valid_suit = 1;
            break;
        }
    }

    return (valid_rank && valid_suit);
}

int load_deckLDCommand(){
    printf("inden i funk");

    //tjek først om ld command er to char eller mere.


    FILE *fp;
    char str[60];

    /* opening file for reading */
    fp = fopen("tryout.txt", "r");
    if(fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while(fgets(str, 60, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);
    return 0;

}

// Function to load a deck of cards from a file or create a new unshuffled deck if no filename is given
int load_deck(char* filename) {


    FILE *fp;
    char buffer[20];

    //check if filename is entered.


    int card_count = 0, line_number = 0, error = 0;

    if (filename == NULL) {
        // Create a new unshuffled deck of cards
        for (int i = 0; i < NUM_SUITS; i++) {
            for (int j = 0; j < NUM_CARDS_PER_SUIT; j++) {
                strcpy(deck[card_count].rank, ranks[j]);
                strcpy(deck[card_count].suit, suits[i]);
                card_count++;
            }
        }
        printf("OK\n");
        return 0;
    }

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        // File does not exist
        printf("Error: File does not exist\n");
        return -1;
    }

    // Read each line of the file
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        line_number++;
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Parse the line into rank and suit
        char *rank = strtok(buffer, " ");
        char *suit = strtok(NULL, " ");

        // Check if the card is valid
        if (!is_valid_card(rank, suit)) {
            printf("Error: Invalid card at line %d\n", line_number);
            error = 1;
            break;
        }

        // Add the card to the deck
        strcpy(deck[card_count].rank, rank);
        strcpy(deck[card_count].suit, suit);
        card_count++;
    }

    fclose(fp);

    // Check for errors
    if (error) {
        return -1;
    }

    if (card_count != NUM_CARDS) {
        printf("Error: Incorrect number of cards in file\n");
        return -1;
    }

}

