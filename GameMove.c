//
// Created by Sabirin on 01/05/2023.
//

#include "headers/AllHeaders.h"
///THIS C FILE WITH ALL THE GAME MOVES THAT CHECKS THE GAME MOVES OF THE USER



bool validColumnRange(char in) {
    if(in >= '1' && in <= '7')
        return true;
    else
        return false;
}

bool validRank(char in) {
    if((in >= '2' && in <= '9') || in == 'A' || in == 'T' || in == 'J' || in == 'Q' || in == 'K')
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

bool validMoveSyntax(char* input, enum moveType *ptr) {
    if(input[0] == 'C' && input[2] == '-' && input[3] == '>' && input[4] == 'C'){
        *ptr = COL_TO_COL;
        return true;

    } else if(input[0] == 'C' && input[2] == '-' && input[3] == '>' && input[4] == 'F') {
        *ptr = COL_TO_FOUND;
        return true;

    } else if(input[0] == 'F' && input[2] == '-' && input[3] == '>' && input[4] == 'C') {
        *ptr = FOUND_TO_COL;
        return true;

    } else if(input[0] == 'C' && input[2] == ':' && input[5] == '-' && input[6] == '>' && input[7] == 'C'){ // moving a stack of cards from one column to another
        *ptr = PILE_TO_COL;
        return true;

    } else { return false; }

}

bool validInputFromTailToTail(char* input) {
    if(input[0] != 'C' || input[4] != 'C')
        return false;

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
    if(input[0] != 'C' || input[4] != 'F')
        return false;

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
    if(input[0] != 'C' || input[7] != 'C')
        return false;

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
