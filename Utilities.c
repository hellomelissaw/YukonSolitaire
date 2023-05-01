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
    printf("%s", abs_path);

#else
    getcwd(cwd, sizeof(cwd));
    char* abs_path = malloc(MAX_PATH);
    chdir(".."); // go to parent dir to get absolute file path from project's parent directory
    abs_path = realpath(fileName, NULL);
    chdir(cwd);
#endif

    return abs_path;
}


void PrintMessage() {
    char *message = "First message";
    char **messagePtr = &message;
    printf("%s", message);

    char *newMessage = malloc(100);

    strcpy(newMessage, "Second message");
    setMessage(messagePtr, newMessage);
    printf("%s", message);
}

void setMessage(char** messagePtr, char* message) {
    char *newMessage = malloc(100);
    strcpy(newMessage, message);
    (*messagePtr) = newMessage;
}




/*
/// FUNCTION TO GET THE ABSOLUTE PATH TO ANY GIVEN FILE
/// \param fileName char array of the name of the file to find the path to
/// \return pointer
char* getAbs_path(char fileName[]) {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));

    chdir(".."); // go to parent dir to get absolute file path from project's parent directory
    char* abs_path = (char *)  realpath(fileName, NULL);
    chdir(cwd);

    return abs_path;
}*/