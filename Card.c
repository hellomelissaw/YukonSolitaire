//
// Created by Watson on 2023-04-15.
//
#include <stdbool.h>
#include <stdlib.h>

typedef struct Card
{
    char rank;
    char suit;
    struct Card *next;
    bool isVisible;

} Card;


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

