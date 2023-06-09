
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/AllHeaders.h"
#include <unistd.h>

#define NUM_SUITS 4
#define NUM_CARDS_PER_SUIT 13
#define NUM_CARDS 52

// Arrays to store suit and rank names
char* suits[] = {"C", "D", "H", "S"};
char* ranks[] = {"A", "2", "3", "4", "5", "6", "7",
                 "8", "9", "T", "J", "Q", "K"};


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
// Function to load a deck of cards from a file or create a new unshuffled deck if no filename is given

Card* load_DefaultDeckLDCommand(char** ptrMessage) {
    FILE *fp;
    char str[100];
    Card* head = NULL;
    /* opening file for reading */

    char* abspath = getAbs_path("defaultDeckOfFile.txt");
    fp = fopen(abspath, "r");
    if (fp == NULL) {
        setMessage(ptrMessage, "Error opening file");

    } else {
        setMessage(ptrMessage, "Deck loaded successfully.");
        #ifdef _WIN32
        head = createDeck("..\\defaultDeckOfFile.txt");
        #else
        head = createDeck("defaultDeckOfFile.txt");
        #endif

    }


    // printBoard(abspath);
    fclose(fp);
    return head;

}
// return true if the file specified by the filename exists
bool file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL) {
        // check if we can read from the file
        if (fgetc(fp) != EOF) {
            is_exist = true;
        }
        fclose(fp); // close the file
    }
    return is_exist; //else not true, does not exist.
}


Card * load_SpecificFileIntoDeck(char *filename, char** ptrMessage) {
    Card* head = NULL;
    char c;
    int count = 0;
    char countFileLine;
    filename[strcspn(filename, "\n")] = '\0';
    char* abs_path = getAbs_path(filename);
    FILE *file = fopen(abs_path, "r"); // open file in read mode
    if (file_exists(filename) || file != NULL) {
        //printf("File %s exists", filename);
        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                count++;
            }
        }
        count++;
        if (count == 52) {
            char line[3]; // allocate space for each line
            while (fgets(line, sizeof(line), file)) {
                if (strlen(line) == 2) {
                    countFileLine++;
                }
            }
            fclose(file);
        #ifdef _WIN32
            char filenameWindows[90];
            char* filename = "untitled.txt";
            char* db_backslash = "..\\";
            snprintf(filenameWindows, sizeof(filenameWindows), "%s%s", db_backslash, filename);
            //printf("%s", filenameWindows);
            head = createDeck(filenameWindows);
            #else
            head = createDeck(filename);
            #endif

            setMessage(ptrMessage,"Custom file is accepted.");
        } else {
            setMessage(ptrMessage, "The file does not have 52 cards");
        }

    } else
        setMessage(ptrMessage, "The file doesnt exist");
    return head;
}