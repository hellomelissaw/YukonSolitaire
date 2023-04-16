//
// Created by Watson on 2023-04-16.
//
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/// FUNCTION TO GET THE ABSOLUTE PATH TO ANY GIVEN FILE
/// \param fileName char array of the name of the file to find the path to
/// \return pointer
char* getAbs_path(char fileName[]) {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));

    chdir(".."); // go to parent dir to get absolute file path from project's parent directory
    char* abs_path = realpath(fileName, NULL);
    chdir(cwd);

    return abs_path;
}