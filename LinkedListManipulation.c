//
// Created by Watson on 2023-04-15.
//
#include <stdio.h>
#include "include/Card.h"

void insertAtTail(Card** ptrShuffledHead, Card** ptrshuffledTail, Card** ptrUnshuffledHead) {

    if(*ptrShuffledHead == NULL) { // if the values at ptrShuffledHead are NULL
        *ptrShuffledHead = *ptrUnshuffledHead;


    } else {(*ptrshuffledTail)->next = *ptrUnshuffledHead;} // or else set the values for the next node after ptrshuffledTail

    *ptrshuffledTail = *ptrUnshuffledHead; // the address of ptrshuffledTail should now be ptrUnshuffledHead
    *ptrUnshuffledHead = (*ptrUnshuffledHead)->next;
    (*ptrshuffledTail)->next = NULL;
}

void insertAtHead(Card** ptrShuffledHead, Card** ptrUnshuffledHead) {
    Card* tempPointer = (*ptrUnshuffledHead)->next;

    if(*ptrShuffledHead == NULL) { // checks if the values at the address ptrShuffledHead is pointing to are NULL
        *ptrShuffledHead = *ptrUnshuffledHead;
        (*ptrShuffledHead)->next = NULL;

    } else {
        (*ptrUnshuffledHead)->next = *ptrShuffledHead;
        *ptrShuffledHead = *ptrUnshuffledHead; // update the address of the pointer pointing to the head of the deck
    }
    *ptrUnshuffledHead = tempPointer;

}

void insertBetween(Card** ptrShuffledHead, Card** ptrshuffledTail, Card** ptrUnshuffledHead, int numNodesToTraverse) {
    Card* tempPointer = (*ptrUnshuffledHead)->next;
    Card* current = *ptrShuffledHead;
    for(int i = 0 ; i < numNodesToTraverse ; i++) {
        current = current->next;
    }

    if (*ptrShuffledHead == NULL || current->next == NULL) {
        insertAtTail(ptrShuffledHead, ptrshuffledTail, ptrUnshuffledHead);

    } else {

        (*ptrUnshuffledHead)->next = current->next;
        current->next = *ptrUnshuffledHead;
        *ptrUnshuffledHead = tempPointer;

    }
}



