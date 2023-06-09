//
// Created by Watson on 2023-04-15.
//

#include <stdbool.h>
#include <stdlib.h>
#include "headers/AllHeaders.h"

/// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
/// \param rank is the rank of the card in the range of 2-9 and T, J, Q, K
/// \param suit is the suit of the card represented by C (Clubs) D (Diamonds) H (Hearts) and S (Spades)
/// \return returns the pointer containing the memory address to the newly created Card struct
Card* createCard(char rank, char suit) {
    Card* card_node = malloc(sizeof(Card)); // card_node is a pointer containing the mem adr to new Card struct
    card_node->rank = rank;
    card_node->suit = suit;
    card_node->view[0] = rank;
    card_node->view[1] = suit;
    card_node->view[2] = '\0';
    return card_node;
}

void setVisibility(Card** currentCards , bool visible){

    if (visible) {
        (*currentCards)->isVisible = true;
        (*currentCards)->view[0] = (*currentCards)->rank;
        (*currentCards)->view[1] = (*currentCards)->suit;
        (*currentCards)->view[2] = '\0'; // this says that the string has no more chars


    }else{
        (*currentCards)->isVisible = false;
        (*currentCards)->view[0] = '[';
        (*currentCards)->view[1] = ']';
        (*currentCards)->view[2] = '\0';

    }

}


