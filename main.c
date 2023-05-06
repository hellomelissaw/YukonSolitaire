//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/AllHeaders.h"

// Hey girl hey
int main() {
    //testInsertAtHeadInsertAtTail();
    //testInsertAtTail(140);
    //testMoving10To9();
    //printDeck(createDeck("defaultDeckOfFile.txt"));
    //Card *head = createDeck("C:\\Users\\Bruger\\Desktop\\DTU\\Machine Oriented programing\\YukonSolitaire\\defaultDeckOfFile.txt");
    //Card *head = createDeck("C:\\Users\\Bruger\\Desktop\\DTU\\YukonSolitaire\\defaultDeckOfFile.txt");
    Card* head = NULL;
    Pile **columnsFilled = NULL;
    Pile **foundationsBlank = NULL;
    //Card *head = createDeck("C:\\Users\\Bruger\\Desktop\\DTU\\Machine Oriented programing\\YukonSolitaire\\defaultDeckOfFile.txt");
    //Pile **foundationsBlank = setTestFoundations();
    char *message = "Welcome to Yukon Solitaire. You are in the STARTUP phase. Type CMD to get a list of commands";
    char **ptrMessage = &message;
    char* input = malloc(sizeof(char) * 100);
    char* command = malloc(sizeof(char) * 10);
    char* option = malloc(sizeof(char) * 90);
    MoveList *moveList = NULL;
    MoveList **ptrMoveList = &moveList;

    enum phase phase = SETUP;
    bool isHidden = true;

    while (1) {
        if (head == NULL) {
            printEmptyBoard();

        } else if(head != NULL && phase == SETUP){
            displayLoadedDeck(isHidden, head);

        } else {
            printBoard(columnsFilled, foundationsBlank);

        }

        printUserConsole(ptrMessage);


        //char input[9];
        char str[100];
        char result[100];
        int length;
        enum moveType mt;
        enum moveType *ptrMt = &mt;

        fgets(input, 100, stdin);
        //scanf("%s", input);
        sscanf(input,  "%s %s", command, option);
       // printf("Command is: %s\n", command);
       // printf("Option is: %s\n", option);
        fflush(stdin);

        switch (phase) {
            case SETUP: {
                switch (command[0]) {
                    case 'Q':
                        if (command[1] == 'Q') {
                            free(input);
                            free(command);
                            free(option);
                            exit(0); //return
                        }
                        break;


                    case 'P':
                        if (head == NULL) {
                            setMessage(ptrMessage, "Please load a deck before starting the game.");
                        } else {
                            columnsFilled = setColumnLists(head);
                            foundationsBlank = setFoundationLists();
                            phase = PLAY;
                            setMessage(ptrMessage, "PLAY phase started. TYPE CMD for a list of available commands.");
                        }
                        break;

                    case 'L':
                        if (command[1] == 'D' && option[0] == '\0') {
                            //fgets(str, 100, stdin);
                            length = strlen(input);
                            head = load_DefaultDeckLDCommand(ptrMessage);

                        } else {

                            //strcpy(result, str + 1);
                            //printf("Result: %s\n", result);
                            head = load_SpecificFileIntoDeck(option, ptrMessage);

                        }
                        break;

                    case 'S':
                        if (head != NULL) {
                            switch (command[1]) {
                                case 'W':
                                    isHidden = false;
                                    setMessage(ptrMessage, "Here is the deck you've loaded.");
                                    break;

                                case 'I': {
                                    Card *tempHead = NULL;
                                    if (option[0] != '\0') {
                                        int optionInt = atoi(option); // a to i, ascii to integer
                                        tempHead = shuffleInterweave(optionInt, head);
                                    } else {
                                        tempHead = shuffleInterweave(26, head); // if no option, split down the middle
                                    }
                                    head = tempHead;
                                    setMessage(ptrMessage, "Here is your deck, bridge-shuffled.");
                                    break;
                                }

                                case 'R': {
                                    Card *tempHead = NULL;
                                    tempHead = shuffleRandom(head);
                                    head = tempHead;
                                    setMessage(ptrMessage, "Here is your deck, shuffled randomly.");
                                    break;
                                }

                                default:
                                    setMessage(ptrMessage, "Invalid shuffle command");
                            }
                        } else { setMessage(ptrMessage, "Please load a deck first with command LD."); }
                        break;

                    case 'C':
                        if (command[1] == 'M' && command[2] == 'D') {
                            printCommands(phase, ptrMessage);
                            break;
                        }

                    default:
                        setMessage(ptrMessage, "Command not found.");
                }

                break;// break setup phase
            }

            case PLAY: {
                switch (command[0]) {
                    case 'Q':
                        if (command[1] == 'Q') {
                            exit(0);
                        } else {
                            phase = SETUP;
                            setMessage(ptrMessage,
                                       "You are back to the STARTUP phase. Type CMD for a list of available commands.");
                        }
                        break;
                    case 'C':
                        if (command[1] == 'M' && command[2] == 'D') {
                            printCommands(phase, ptrMessage);
                            break;
                        }
                    case 'F':
                        //   if (head != NULL) {
                        if (validMoveSyntax(input, ptrMt)) {
                            bool validInput = true;
                            int srcIndex = command[1] - 49; // column number from ascii to decimal - 1
                            int destIndex;
                            char srcCardRank;
                            char srcCardSuit;
                            Pile **ptrSrc;
                            Pile **ptrDest;
                            bool moveIsAllowed = false;

                            switch (mt) {
                                case PILE_TO_COL:
                                    if (validInputFromColumnPileToTail(input)) {
                                        destIndex = command[8] - 49;
                                        srcCardRank = command[3];
                                        srcCardSuit = command[4];
                                        ptrSrc = &columnsFilled[srcIndex];
                                        ptrDest = &columnsFilled[destIndex];
                                        if (validateMoveToColumn(srcCardRank, ptrDest, ptrMessage)) {
                                            moveIsAllowed = true;
                                        } else {
                                            setMessage(ptrMessage, "Move is not allowed.");
                                        }

                                    }
                                    break;

                                case COL_TO_COL:
                                    if (validInputFromTailToTail(input)) {
                                        destIndex = command[5] - 49;
                                        srcCardRank = columnsFilled[srcIndex]->tail->rank;
                                        srcCardSuit = columnsFilled[srcIndex]->tail->suit;
                                        ptrSrc = &columnsFilled[srcIndex];
                                        ptrDest = &columnsFilled[destIndex];
                                        if (validateMoveToColumn(srcCardRank, ptrDest, ptrMessage)) {
                                            moveIsAllowed = true;
                                        } else {
                                            setMessage(ptrMessage, "Move is not allowed.");
                                        }

                                    }
                                    break;

                                case COL_TO_FOUND:
                                    if (validInputFromTailToFoundation(command)) {
                                        destIndex = command[5] - 49;
                                        srcCardRank = columnsFilled[srcIndex]->tail->rank;
                                        srcCardSuit = columnsFilled[srcIndex]->tail->suit;
                                        ptrSrc = &columnsFilled[srcIndex];
                                        ptrDest = &foundationsBlank[destIndex];
                                        Card *destTail = foundationsBlank[destIndex]->tail;

                                        if (validateMoveToFoundation(srcCardRank, srcCardSuit, &destTail,
                                                                     ptrMessage)) {
                                            moveIsAllowed = true;
                                        } else { setMessage(ptrMessage, "Move is not allowed."); }

                                    }
                                    break;

                                case FOUND_TO_COL:
                                    if (validInputFromTailToFoundation(command)) {
                                        destIndex = command[5] - 49;
                                        srcCardRank = foundationsBlank[srcIndex]->tail->rank;
                                        srcCardSuit = foundationsBlank[srcIndex]->tail->suit;
                                        ptrSrc = &foundationsBlank[srcIndex];
                                        ptrDest = &columnsFilled[destIndex];
                                        if (validateMoveToColumn(srcCardRank, ptrDest, ptrMessage)) {
                                            moveIsAllowed = true;
                                        } else { setMessage(ptrMessage, "Move is not allowed."); }
                                    }
                                    break;

                                default:
                                    validInput = false;
                            }

                            if (validInput && moveIsAllowed) {
                                moveCards(ptrSrc, ptrDest, srcCardRank, srcCardSuit, ptrMessage);
                                AddMove(ptrSrc, ptrDest, srcCardRank, srcCardSuit, ptrMoveList);

                            }

                            if (foundationsBlank[0]->head != NULL && foundationsBlank[1]->head != NULL &&
                                foundationsBlank[2]->head != NULL && foundationsBlank[3]->head != NULL) {
                                bool foundationsComplete = (foundationsBlank[0]->tail->rank == 'K' &&
                                                            foundationsBlank[1]->tail->rank == 'K' &&
                                                            foundationsBlank[2]->tail->rank == 'K' &&
                                                            foundationsBlank[3]->tail->rank == 'K');
                                if (foundationsComplete) {
                                    setMessage(ptrMessage, "You beat the game!");
                                    printf("\n");
                                    printBoard(columnsFilled, foundationsBlank);
                                }
                            }

                        } else {
                            setMessage(ptrMessage, "Invalid syntax.");
                        }
                        //  } else { setMessage(ptrMessage, "Please load a deck first with command LD."); }
                        break;

                    case 'U' :
                        undoLastMove(ptrMoveList, ptrMessage);
                        break;

                    default:
                        setMessage(ptrMessage, "Unknown command.");

                        } // end commands switch case for play phase

                        break; // break play case
            }


        } // end phase switch case

    } // end while loop
}

void printUserConsole(char** ptrCurrentMsg) {
    printf("LAST command; \n"); //add func
    printf("Message: %s\n", *ptrCurrentMsg); //add func
    //printf("Message: \n"); //add func
    printf("INPUT >");

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
