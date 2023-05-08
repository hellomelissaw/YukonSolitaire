//
// Created by Watson on 2023-05-08.
//

#include "headers/AllHeaders.h"

void testEdgeCaseInputsValidColumnRange() {
    printf("\n\nInput 1: \nExpected: 1 (true), Actual: %d\n", validColumnRange('1'));
    printf("\n\nInput 0: \nExpected: 0 (false), Actual: %d\n", validColumnRange('0'));
    printf("\n\nInput 7: \nExpected: 1 (true), Actual: %d\n", validColumnRange('7'));
    printf("\n\nInput 8: \nExpected: 0 (false), Actual: %d\n", validColumnRange('8'));

}
/*bool validFoundationRange(char in);
bool validRank(char in);
bool validSuit(char in);
bool validInputFromTailToFoundation(char* in);
bool validInputFromTailToTail(char* in);
bool validInputFromColumnPileToTail(char* in);
bool validMoveSyntax(char* input, enum moveType *ptr);*/