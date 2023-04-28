//
// Created by Watson on 2023-04-15.
// Ressources: https://stackoverflow.com/questions/16569239/how-to-use-function-srand-with-time-h
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/AllHeaders.h"
#define CARD_COUNT 52

/// FUNCTION INTERWEAVE-SHUFFLE A DECK (BRIDGE SHUFFLE)
/// \param split integer indicating how many cards should be in the first of two temporary piles used to shuffled
/// \param head pointer to the Card which is at the head of the Linked List of Card structs to be shuffled
/// \return pointer to the Card that is at the head of the Linked List of shuffled Cards
Card* shuffleInterweave(int split, Card* head) {
    /* create first Card in temp Card list1 the create all the rest up to split */
    Card* tempHead1 = NULL;
    Card* current = NULL;
    Card* currentHead = NULL;

    tempHead1 = malloc(sizeof(Card));
    tempHead1->rank = head->rank;
    tempHead1->suit = head->suit;

    current = tempHead1;
    currentHead = head;

    for(int j = 1 ; j < split ; j++){
        current->next = createCard(currentHead->next->rank, currentHead->next->suit);
        current = current->next;
        currentHead = currentHead->next;
    }


/*create first Card in temp list2 then all the other cards until OG list head reaches NULL */
    Card* tempHead2 = NULL;

    tempHead2 = malloc(sizeof(Card));
    currentHead = currentHead->next;
    tempHead2->rank = currentHead->rank;
    tempHead2->suit = currentHead->suit;
    current = tempHead2;
    currentHead = currentHead->next;
    int i = 1;
    while(currentHead != NULL) {
        current->next = createCard(currentHead->rank, currentHead->suit);
        current = current->next;
        currentHead = currentHead->next;
        i++;
    }

    /*Initializing the two first cards in the shuffled deck*/
    Card* shuffledDeckHead = head;
    Card* currentTempHead1 = tempHead1;
    Card* currentTempHead2 = tempHead2;

    shuffledDeckHead->rank = currentTempHead1->rank;
    shuffledDeckHead->suit = currentTempHead1->suit;

    current = shuffledDeckHead;
    currentTempHead1 = currentTempHead1->next;

    while(currentTempHead1 != NULL && currentTempHead2 != NULL) {
        current->next = currentTempHead2;
        currentTempHead2 = currentTempHead2->next;

        current->next->next = currentTempHead1;
        currentTempHead1 = currentTempHead1->next;
        current = current->next->next;
    }


    if(currentTempHead1 == NULL) {
        while(currentTempHead2 != NULL){
            current->next = currentTempHead2;
            current = current->next;
            currentTempHead2 = currentTempHead2->next;
        }

    } else if (currentTempHead2 == NULL) {
        while(currentTempHead1 != NULL) {
            current->next = currentTempHead1;
            current = current->next;
            currentTempHead1 = currentTempHead1->next;
        }
    }

    return shuffledDeckHead;
}

/// FUNCTION TO SHUFFLE A DECK BY RANDOMLY PLACING EACH CARD AT THE HEAD, TAIL
/// OR SOMEWHERE IN THE MIDDLE OF THE SHUFFLED DECK
/// \param head pointer to the Card which is at the head of the Linked List of Card structs to be shuffled
/// \return  pointer to the Card that is at the head of the Linked List of shuffled Cards
Card* shuffleRandom(Card* head) {
    Card* shuffledHead = NULL;
    Card* shuffledTail = NULL;
    Card* unshuffledHead = head;

    Card** ptrShuffledHead = &shuffledHead;
    Card** ptrShuffledTail = &shuffledTail;
    Card** ptrUnshuffledHead = &unshuffledHead;

    srand(time(NULL));
    int picker;
    int i = 0;

    while(unshuffledHead != NULL) {
        picker = (rand() % 3) + 1;

        if(picker == 1) {
            insertAtTail(ptrShuffledHead, ptrShuffledTail, ptrUnshuffledHead);

        } else if(picker == 2) {
            insertAtHead(ptrShuffledHead, ptrUnshuffledHead);

        } else if (picker == 3) {
            if(i < 3) {
                insertBetween(ptrShuffledHead, ptrShuffledTail, ptrUnshuffledHead, 0);

            } else {
                int numNodesToTraverse = (rand() % (i-1) + 1);
                insertBetween(ptrShuffledHead, ptrShuffledTail, ptrUnshuffledHead, numNodesToTraverse);
            }
        }
        i++;
    }


    return shuffledHead;
}
