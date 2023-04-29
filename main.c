//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/AllHeaders.h"
//#include "loadDeck.c"
bool validColumnRange(char in);
bool validFoundationRange(char in);
bool validRank(char in);
bool validSuit(char in);
bool validInputFromTailToFoundation(char* in);
bool validInputFromTailToTail(char* in);
bool validInputFromColumnPileToTail(char* in);
void printUserConsole(char** ptrCurrentMsg);
bool validMoveSyntax(char* input);

        int load_DefaultDeckLDCommand() {
    FILE *fp;
    char str[100];

    /* opening file for reading */

    char* abspath = getAbs_path("defaultDeckOfCards");
    fp = fopen(abspath, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }


   // printBoard(abspath);
    fclose(fp);
    return 0;

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


int load_SpecificFileIntoDeck(char *filename) {
    char c;
    char count;
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

        if (countFileLine == 52) {
            char line[3]; // allocate space for each line
            while (fgets(line, sizeof(line), file)) {
                if (strlen(line) == 2) {
                    countFileLine++;
                }
            }
            fclose(file);
        } else {
            printf("The file does not have 52 lines.");
        }

    } else
        printf("File %s doesn't exist.", filename);

    return 0;
}



/*void startPlayPhase() {
    Card* head = createDeck("defaultDeckOfFile.txt");
    Pile** columnsFilled = setColumnLists(head);
    Pile** foundationsBlank = setFoundationLists();
    printBoard(columnsFilled, foundationsBlank);

}*/

// Hey girl hey
int main() {
    //printDeck(createDeck("defaultDeckOfFile.txt"));
    Card *head = createDeck("defaultDeckOfFile.txt");
    Pile **columnsFilled = setColumnLists(head);
    Pile **foundationsBlank = setFoundationLists();
    char *message = " ";
    char **ptrMessage = &message;

    while (1) {
        printBoard(columnsFilled, foundationsBlank);
        printUserConsole(ptrMessage);


        char input[9];
        char str[100];
        char result[100];
        int length;

        scanf("%s", input);


        if (!strcmp(input, "QQ")) {
            // setPrintMessage("Quitting the Game");
            //printf("Quitting The Game");
            exit(0); //return
        }
        if (!strcmp(input, "LD")) {
            fgets(str, 100, stdin);
            length = strlen(str);

            printf("Length of |%s| is |%d|\n", str, length);

            if (length == 1) {
                printf("vi er her");
                load_DefaultDeckLDCommand();


            } else if (length > 1) {

                strcpy(result, str + 1);

                printf("Result: %s\n", result);
                load_SpecificFileIntoDeck(result);
            }
        }

        if (validMoveSyntax(input)) { // checks if the syntax of the input is valid for moving a/many card(s)
            int srcIndex = input[1] - 49; // column number from ascii to decimal - 1
            int destIndex = input[5] - 49;
            char srcCardRank;
            char srcCardSuit;

            bool validCards = false;
            if(input[2] == ':') // move a specific card in a column
                validCards = validInputFromColumnPileToTail(input);
            else if (input[2] == '-') { // move the tail of a column or foundation
                if ((input[0] == 'C' && input[4] == 'C') || (input[0] == 'F' && input[4] == 'C')) {
                    validCards = validInputFromTailToTail(input);

                } else if (input[0] == 'C' && input[4] == 'F') {
                    validCards = validInputFromTailToFoundation(input);
                } else {
                    setMessage(ptrMessage, "Invalid syntax.");
                }
            }

            if (validCards) {
                Pile** ptrSrc;
                Pile** ptrDest;

                if(input[0] == 'C'){
                    ptrSrc = &columnsFilled[srcIndex];
                    srcCardRank = columnsFilled[srcIndex]->tail->rank;
                    srcCardSuit = columnsFilled[srcIndex]->tail->suit;
                    if(input[4] == 'C'){
                        ptrDest = &columnsFilled[destIndex];

                    } else if (input[4] == 'F') {
                       ptrDest = &foundationsBlank[destIndex];
                    }


                } else if (input[0] == 'F') {
                    ptrSrc = &foundationsBlank[srcIndex];
                    ptrDest = &columnsFilled[destIndex];
                    srcCardRank = foundationsBlank[srcIndex]->tail->rank;
                    srcCardSuit = foundationsBlank[srcIndex]->tail->suit;
                }

                moveCards(ptrSrc, ptrDest, srcCardRank, srcCardSuit, ptrMessage);

            }
        }
    }
}

void printUserConsole(char** ptrCurrentMsg) {
    printf("LAST command; \n"); //add func
    printf("Message: %s\n", *ptrCurrentMsg); //add func
    //printf("Message: \n"); //add func
    printf("INPUT >");

}

bool validMoveSyntax(char* input) {
    if((input[0] == 'C' && input[2] == '-' && input[3] == '>' && input[4] == 'C')// moving a bottom card to the bottom of another column
    || (input[0] == 'C' && input[2] == '-' && input[3] == '>' && input[4] == 'F') // moving a bottom card to a foundation pile
    || (input[0] == 'F' && input[2] == '-' && input[3] == '>' && input[4] == 'C') // moving a top foundation card to bottom of a column
    || (input[0] == 'C' && input[2] == ':' && input[5] == '-' && input[6] == '>' && input[7] == 'C') // moving a stack of cards from one column to another
    )  {
        return true;
    } else {
        return false;
    }

    }

bool validInputFromTailToTail(char* input) {
    if(validColumnRange(input[1])){
        if(validColumnRange(input[5]))
            return true;
        else
            return false; // invalid destination column range, if time set message
    } else {
        return false; // invalid source column range, if time set message
    }

}

bool validInputFromTailToFoundation(char* input) {
    if(validColumnRange(input[1])){
        if(validFoundationRange(input[5]))
            return true;
        else
            return false; // invalid destination foundation range, if time set message
    } else {
        return false; // invalid source column range, if time set message
    }
}


bool validInputFromColumnPileToTail(char* input) {
    if(validColumnRange(input[1])){
        if(validRank(input[3])){
            if(validSuit(input[4])){
                if(validColumnRange(input[8]))
                    return true;
                else return false; // invalid destination column range

            } else {
                return false; // invalid source card suit
            }
        } else {
            return false; // invalid source card rank,, if time set message
        }
    } else {
        return false; // invalid source column range, if time set message
    }
}

bool validColumnRange(char in) {
    if(in >= '1' && in <= '7')
        return true;
    else
        return false;
}

bool validRank(char in) {
    if((in >= 2 && in <= 9) || in == 'A' || in == 'T' || in == 'J' || in == 'Q' || in == 'K')
        return true;
    else
        return false;
}

bool validSuit(char in) {
    if(in == 'C' || in == 'D' || in == 'S' || in == 'H')
        return true;
    else
        return false; // invalid suit, set message if time

}

bool validFoundationRange(char in) {
    if(in >= '1' && in <= '4')
        return true;
    else
        return false;
}
/*

    //createDeck("unshuffledCards.txt");
    //printDeck(shuffleInterweave(13, createDeck("unshuffledCards.txt")));

    ///////////////////////////////////////////////////////////////////////////////
    // TEST CREATION OF COLUMNS (need to get headers to work before it works again)
    ///////////////////////////////////////////////////////////////////////////////

    Card* testDeck = createDeck("unshuffledcards.txt");
    Pile** firstColumn = setColumnLists(testDeck);
    Pile** foundations = setFoundationLists();
    printBoard(firstColumn,foundations);

    //////////////////////
    // TEST MOVING CARDS
    //////////////////////
    moveFirstCardToFoundatationTest();

    // move2CToFoundatationTest();

    // move3CToFoundatationTest();

    // testMove2Cn3CToColumnWithAS();

    // testAccessingNextCard();

    ///////////////////
    // TEST SHUFFLE
    ///////////////////

    Card* testDeck = createDeck("unshuffledCards.txt");
    //shuffleRandom(testDeck);
    shuffleInterweave(45, testDeck);
    printDeck(testDeck);*
}
*/
