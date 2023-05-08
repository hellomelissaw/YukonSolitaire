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
void testEdgeCasesValidFoundationRange(){
    printf("\n\nInput 1: \nExpected: 1 (true), Actual: %d\n", validFoundationRange('1'));
    printf("\n\nInput 0: \nExpected: 0 (false), Actual: %d\n", validFoundationRange('0'));
    printf("\n\nInput 4: \nExpected: 1 (true), Actual: %d\n", validFoundationRange('4'));
    printf("\n\nInput 5: \nExpected: 0 (false), Actual: %d\n", validFoundationRange('5'));
}
void testValidRank(){
    printf("\n\nInput @: Expected: 0 (false), Actual: %d\n", validRank('@'));
    printf("\n\nInput A: Expected: 1 (true), Actual: %d\n", validRank('A'));
    printf("\n\nInput B: Expected: 0 (false), Actual: %d\n", validRank('B'));
    printf("\n\nInput 1: Expected: 0 (false), Actual: %d\n", validRank('1'));
    printf("\n\nInput 2: Expected: 1 (true), Actual: %d\n", validRank('2'));
    printf("\n\nInput 9: Expected: 1 (true), Actual: %d\n", validRank('9'));
    printf("\n\nInput : : Expected: 0 (false), Actual: %d\n", validRank(':'));
    printf("\n\nInput S: Expected: 0 (false), Actual: %d\n", validRank('S'));
    printf("\n\nInput T: Expected: 1 (true), Actual: %d\n", validRank('T'));
    printf("\n\nInput U: Expected: 0 (false), Actual: %d\n", validRank('U'));
    printf("\n\nInput I: Expected: 0 (false), Actual: %d\n", validRank('I'));
    printf("\n\nInput J: Expected: 1 (true), Actual: %d\n", validRank('J'));
    printf("\n\nInput K: Expected: 1 (true), Actual: %d\n", validRank('K'));
    printf("\n\nInput L: Expected: 0 (false), Actual: %d\n", validRank('L'));
    printf("\n\nInput P: Expected: 0 (false), Actual: %d\n", validRank('P'));
    printf("\n\nInput Q: Expected: 1 (true), Actual: %d\n", validRank('Q'));
    printf("\n\nInput R: Expected: 0 (false), Actual: %d\n", validRank('R'));



}
/*
bool validSuit(char in);
bool validInputFromTailToFoundation(char* in);
bool validInputFromTailToTail(char* in);
bool validInputFromColumnPileToTail(char* in);
bool validMoveSyntax(char* input, enum moveType *ptr);*/