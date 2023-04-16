//
// Created by Watson on 2023-04-15.
//
#include <stdbool.h>

typedef struct Card
{
    char rank;
    char suit;
    struct Card *next;
    bool isVisible;

} Card;


// FUNCTION TO CREATE AND RETURN A NEW CARD (NODE IN LINKED LIST)
Card* createCard(char rank, char suit) {
    Card* card_node = malloc(sizeof(Card));
    card_node->rank = rank;
    card_node->suit = suit;
    return card_node;
}

