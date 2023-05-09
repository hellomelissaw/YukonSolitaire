//
// Created by Watson on 2023-04-30.
//

#ifndef YUKONSOLITAIRE_MAIN_H
#define YUKONSOLITAIRE_MAIN_H
#include <stdbool.h>

bool validColumnRange(char in);
bool validFoundationRange(char in);
bool validRank(char in);
bool validSuit(char in);
int main();
bool validInputFromTailToFoundation(char* in);
bool validInputFromTailToTail(char* in);
bool validInputFromColumnPileToTail(char* in);
void printUserConsole(char **ptrCurrentMsg, char **input);
bool validMoveSyntax(char* input, enum moveType *ptr);

#endif //YUKONSOLITAIRE_MAIN_H
