//
// Created by Watson on 2023-04-28.
//

#ifndef YUKONSOLITAIRE_UTILITIES_H
#define YUKONSOLITAIRE_UTILITIES_H
enum phase {
    SETUP,
    PLAY
};

char* getAbs_path(char fileName[]);
void setMessage(char** ptrMessage, char message[]);
char* printPath(char *filename);
void printCommands(enum phase currentPhase, char **ptrMessage);

#endif //YUKONSOLITAIRE_UTILITIES_H
