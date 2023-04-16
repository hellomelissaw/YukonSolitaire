//
// Created by Watson on 2023-04-15.
//
#include <stdio.h>

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE TAIL OF ANOTHER DECK
/// \param ptr_deck2Head pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_deck2Tail pointer containing the mem adr of the pointer to tail of deck to be inserted TO
/// \param ptr_deck1Head pointer containing the mem adr of the pointer to head deck to be inserted FROM
void insertAtTail(Card** ptr_deck2Head, Card** ptr_deck2Tail, Card** ptr_deck1Head) {

    if(*ptr_deck2Head == NULL) { // if the values at ptr_deck2Head are NULL
        *ptr_deck2Head = *ptr_deck1Head;


    } else {(*ptr_deck2Tail)->next = *ptr_deck1Head;} // or else set the values for the next node after ptr_deck2Tail

    *ptr_deck2Tail = *ptr_deck1Head; // the address of ptr_deck2Tail should now be ptr_deck1Head
    *ptr_deck1Head = (*ptr_deck1Head)->next;
    (*ptr_deck2Tail)->next = NULL;
}

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE HEAD OF ANOTHER DECK
/// \param ptr_deck2Head pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_deck1Head pointer containing the mem adr of the pointer to head deck to be inserted FROM
void insertAtHead(Card** ptr_deck2Head, Card** ptr_deck1Head) {
    Card* tempPointer = (*ptr_deck1Head)->next;

    if(*ptr_deck2Head == NULL) { // checks if the values at the address ptr_deck2Head is pointing to are NULL
        *ptr_deck2Head = *ptr_deck1Head;
        (*ptr_deck2Head)->next = NULL;

    } else {
        (*ptr_deck1Head)->next = *ptr_deck2Head;
        *ptr_deck2Head = *ptr_deck1Head; // update the address of the pointer pointing to the head of the deck
    }
    *ptr_deck1Head = tempPointer;

}

/// INSERTS THE CURRENT HEAD OF ONE DECK AT A GIVEN SPOT BETWEEN THE HEAD AND THE TAIL OF ANOTHER DECK
/// \param ptr_deck2Head pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_deck2Tail pointer containing the mem adr of the pointer to tail of deck to be inserted TO
/// \param ptr_deck1Head pointer containing the mem adr of the pointer to head deck to be inserted FROM
/// \param numNodesToTraverse integer indicating how many Card nodes to traverse before inserting Card
void insertBetween(Card** ptr_deck2Head, Card** ptr_deck2Tail, Card** ptr_deck1Head, int numNodesToTraverse) {
    Card* tempPointer = (*ptr_deck1Head)->next;
    Card* current = *ptr_deck2Head;
    for(int i = 0 ; i < numNodesToTraverse ; i++) {
        current = current->next;
    }

    if (*ptr_deck2Head == NULL || current->next == NULL) {
        insertAtTail(ptr_deck2Head, ptr_deck2Tail, ptr_deck1Head);

    } else {

        (*ptr_deck1Head)->next = current->next;
        current->next = *ptr_deck1Head;
        *ptr_deck1Head = tempPointer;

    }
}



