//
// Created by Watson on 2023-04-15.
//
#include <stdbool.h>
#include <stdlib.h>

typedef struct Card
{
    char rank;
    char suit;
    char view[2]; // if the card is unvisible showes [], if visible shoes rank and suit
    struct Card *next;
    bool isVisible;
   /* if(isVisible){
        view = 'rank suit'
    } else { view = []}*/

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
void visibility(Card** cardView, bool visibility){
    (*cardView)->isVisible = visibility;

}

void setVisibility(Card** cardView[] ,bool visibility){
    Card* currentCard;
    if (visibility) {
        // If visibility is true, assign the rank and suit pointers to the cardView array
        cardView[0] = &(currentCard->rank);
        cardView[1] = &(currentCard->suit);
    }else{
        // If visibility is false, assign null pointers to the cardView array
        cardView[0] = NULL;
        cardView[1] = NULL;
    }
}

