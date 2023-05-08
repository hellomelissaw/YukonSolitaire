//
// Created by Watson on 2023-04-16.
//
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "headers/AllHeaders.h"


#ifdef _WIN32 // If on Windows
#include <direct.h>
    #define GetCurrentDir _getcwd
#else // If on Mac or Linux
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

char* getAbs_path(char fileName[]) {
    char cwd[PATH_MAX];
#ifdef _WIN32
    /*char full_path[_MAX_PATH];
     * char* abs_path = malloc(_MAX_PATH);
    if (_fullpath(full_path, fileName, _MAX_PATH) != NULL) {
        abs_path = full_path;
    } else {
        // handle error case
        abs_path = NULL;
    }
    _getcwd(cwd, sizeof(cwd));
    char *abs_path = NULL;

    char *rel_path = fileName;*/
    char* abs_path = malloc(_MAX_PATH);
    _fullpath(abs_path, fileName, _MAX_PATH);
    //printf("fullpath string: %s\n", abs_path);
    return abs_path;
    char fixed_path[_MAX_PATH];
    strncpy(fixed_path, abs_path, sizeof(fixed_path));
    char* ptrFixedPath = fixed_path;
    for (size_t i = 0; i < strlen(fixed_path); i++) {
        //if (fixed_path[i] == "\\") {
        //    fixed_path[i] = "\\\\";
        //   }
     }
    printf("%s\n", fixed_path);
    return ptrFixedPath;

#else
    getcwd(cwd, sizeof(cwd));
    char* abs_path = malloc(PATH_MAX);
    chdir(".."); // go to parent dir to get absolute file path from project's parent directory
    abs_path = realpath(fileName, NULL);
    chdir(cwd);
    return abs_path;
#endif

}


void setMessage(char** messagePtr, char* message) {
    if(messagePtr != NULL) {
        char *newMessage = malloc(100);
        strcpy(newMessage, message);
        (*messagePtr) = newMessage;
    }
}

void printCommands(enum phase currentPhase, char **ptrMessage) {
    if(currentPhase == SETUP) {
        setMessage(ptrMessage,"The available commands in SETUP are:\n- LD to load default deck\n- SW to show all cards in loaded deck\n- SR to randomly shuffle loaded deck\n- SI to bridge-shuffle loaded deck\n- P to start the game\n- QQ to quit the game\n"
        );

    } else if (currentPhase == PLAY) {
        char commands[600];
        char* intro = "The available commands in PLAY are: \n";
        char* CtoC = "- Cx->Cy to move a card from the bottom of a column to another column, where x is source column number and y is destination number (fx C7->C3)\n";
        char* CtoF = "- Cx->Fy to move a card from the bottom of a column to a foundation pile, where x is source column number and y is foundation number (fx C1->F1)\n";
        char* PtoC = "- Cx:RS->Cy to move a set of card to another column, where x is the column number, R is the rank and S the suit of the card to be moved and y the destination number (fx C3:7H->C2)\n";
        char* quit = "- Q to quit the game and return to the SETUP page\n";
        char* quitquit = "- QQ to quit the game completely.\n";
        snprintf(commands, sizeof(commands), "%s%s%s%s%s%s", intro, CtoC, CtoF, PtoC, quit, quitquit);
        setMessage(ptrMessage, commands);
    } else {
        setMessage(ptrMessage, "Invalid phase.");
    }
}