//
// Created by Watson on 2023-05-08.
//

#include "headers/AllHeaders.h"

void testEdgeCaseInputsValidColumnRange() {
    printf("\n\nInput 1: \nExpected: 1 (true), Actual: %d\n", validColumnRange('1'));
    printf("Input 0: \nExpected: 0 (false), Actual: %d\n", validColumnRange('0'));
    printf("Input 7: \nExpected: 1 (true), Actual: %d\n", validColumnRange('7'));
    printf("Input 8: \nExpected: 0 (false), Actual: %d\n", validColumnRange('8'));

}
void testEdgeCasesValidFoundationRange(){
    printf("\n\nInput 1: \nExpected: 1 (true), Actual: %d\n", validFoundationRange('1'));
    printf("Input 0: \nExpected: 0 (false), Actual: %d\n", validFoundationRange('0'));
    printf("Input 4: \nExpected: 1 (true), Actual: %d\n", validFoundationRange('4'));
    printf("Input 5: \nExpected: 0 (false), Actual: %d\n", validFoundationRange('5'));
}
void testValidRank(){
    printf("\n\nInput @: Expected: 0 (false), Actual: %d\n", validRank('@'));
    printf("Input A: Expected: 1 (true), Actual: %d\n", validRank('A'));
    printf("Input B: Expected: 0 (false), Actual: %d\n", validRank('B'));
    printf("Input 1: Expected: 0 (false), Actual: %d\n", validRank('1'));
    printf("Input 2: Expected: 1 (true), Actual: %d\n", validRank('2'));
    printf("Input 9: Expected: 1 (true), Actual: %d\n", validRank('9'));
    printf("Input : : Expected: 0 (false), Actual: %d\n", validRank(':'));
    printf("Input S: Expected: 0 (false), Actual: %d\n", validRank('S'));
    printf("Input T: Expected: 1 (true), Actual: %d\n", validRank('T'));
    printf("Input U: Expected: 0 (false), Actual: %d\n", validRank('U'));
    printf("Input I: Expected: 0 (false), Actual: %d\n", validRank('I'));
    printf("Input J: Expected: 1 (true), Actual: %d\n", validRank('J'));
    printf("Input K: Expected: 1 (true), Actual: %d\n", validRank('K'));
    printf("Input L: Expected: 0 (false), Actual: %d\n", validRank('L'));
    printf("Input P: Expected: 0 (false), Actual: %d\n", validRank('P'));
    printf("Input Q: Expected: 1 (true), Actual: %d\n", validRank('Q'));
    printf("Input R: Expected: 0 (false), Actual: %d\n", validRank('R'));

}

void testValidSuit(){
    printf("\n\nInput B: Expected: 0 (false), Actual: %d\n", validSuit('B'));
    printf("Input C: Expected: 1 (true), Actual: %d\n", validSuit('C'));
    printf("Input D: Expected: 1 (true), Actual: %d\n", validSuit('D'));
    printf("Input E: Expected: 0 (false), Actual: %d\n", validSuit('E'));
    printf("Input G: Expected: 0 (false), Actual: %d\n", validSuit('G'));
    printf("Input H: Expected: 1 (true), Actual: %d\n", validSuit('H'));
    printf("Input I: Expected: 0 (false), Actual: %d\n", validSuit('I'));
    printf("Input R: Expected: 0 (false), Actual: %d\n", validSuit('R'));
    printf("Input S: Expected: 1 (true), Actual: %d\n", validSuit('S'));
    printf("Input T: Expected: 0 (false), Actual: %d\n", validSuit('T'));


}

void testValidInputFromTailToFoundation(){
    printf("Input C1->F1: Expected: 1 (true), Actual: %d\n", validInputFromTailToFoundation("C1->F1"));
    printf("Input B1->F1: Expected: 0 (false), Actual: %d\n", validInputFromTailToFoundation("B1->F1"));
    printf("Input C1->R1: Expected: 0 (false), Actual: %d\n", validInputFromTailToFoundation("C1->R1"));

}
void testValidInputFromTailToTail(){
    printf("Input C1->C7: Expected: 1 (true), Actual: %d\n", validInputFromTailToTail("C1->C7"));
    printf("Input B1->C2: Expected: 0 (false), Actual: %d\n", validInputFromTailToTail("B1->C2"));
    printf("Input C1->R2: Expected: 0 (false), Actual: %d\n", validInputFromTailToTail("C1->R2"));

}
void testValidInputFromColumnPileToTail(){
    printf("Input C1:QS->C2: Expected: 1 (true), Actual: %d\n", validInputFromColumnPileToTail("C1:QS->C2"));
    printf("Input F1:QS->C2: Expected: 0 (false), Actual: %d\n", validInputFromColumnPileToTail("F1:QS->C2"));
    printf("Input C1:QS->F2: Expected: 0 (false), Actual: %d\n", validInputFromColumnPileToTail("C1:QS->F2"));

}
