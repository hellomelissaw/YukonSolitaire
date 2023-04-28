//
// Created by Watson on 2023-04-15.
//
#include <stdbool.h>
#include <stdlib.h>
#include "headers/Card.h"

/*typedef struct Card
{
    char rank;
    char suit;
    char view[3]; // if the card is unvisible showes [], if visible showes rank and suit
    struct Card *next;
    bool isVisible;

} Card;*/


/// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
/// \param rank is the rank of the card in the range of 2-9 and T, J, Q, K
/// \param suit is the suit of the card represented by C (Clubs) D (Diamonds) H (Hearts) and S (Spades)
/// \return returns the pointer containing the memory address to the newly created Card struct
Card* createCard(char rank, char suit) {
    Card* card_node = malloc(sizeof(Card)); // card_node is a pointer containing the mem adr to new Card struct
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}
void visibility(Card** cardView, bool visibility){
    (*cardView)->isVisible = visibility;

}

void setVisibility(Card** currentCards , bool visible){
   // Card* currentCard;
    if (visible) {
        // If visible is true, assign the rank and suit pointers to the currentCards array
       // currentCards[0] = &(currentCard->rank);
        //currentCards[1] = &(currentCard->suit);
        (*currentCards)->view[0] = (*currentCards)->rank;
        (*currentCards)->view[1] = (*currentCards)->suit;
        (*currentCards)->view[2] = '\0'; // this says that the string has no more chars


    }else{
        // If visible is false, assign null pointers to the currentCards array
        //currentCards[0] = "[";
        //currentCards[1] = "]";
        //currentCards[0] = &(currentCard->rank);
        //currentCards[1] = &(currentCard->suit);
        (*currentCards)->view[0] = '[';
        (*currentCards)->view[1] = ']';
        (*currentCards)->view[2] = '\0';

    }

}

