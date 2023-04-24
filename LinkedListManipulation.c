//
// Created by Watson on 2023-04-15.
//
#include <stdio.h>
//#include "Card.c"

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE TAIL OF ANOTHER DECK
/// \param ptr_DestHead pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_DestTail pointer containing the mem adr of the pointer to tail of deck to be inserted TO
/// \param ptr_SrcHead pointer containing the mem adr of the pointer to head deck to be inserted FROM
void insertAtTail(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail) {
    if(*ptr_DestHead == NULL) { // if the values at ptr_DestHead are NULL
        *ptr_DestHead = *ptr_SrcHead;

    } else {(*ptr_DestTail)->next = *ptr_SrcHead;
    } // or else set the values for tail->next (which is currently NULL) to src head

    *ptr_DestTail = *ptr_SrcHead;// the address of ptr_DestTail should now be ptr_SrcHead
    *ptr_SrcHead = (*ptr_SrcHead)->next;
    (*ptr_DestTail)->next = NULL;
   /* if(*ptr_DestHead == NULL) { // if the values at ptr_DestHead are NULL
        *ptr_DestHead = *ptr_SrcHead;

    } else if((*ptr_DestHead)->next == NULL){
        *ptr_DestTail = *ptr_SrcHead;
        (*ptr_SrcHead)->next = *ptr_DestTail;

    } else {(*ptr_DestTail)->next = *ptr_SrcHead;
        *ptr_DestTail = *ptr_SrcHead;
    } // or else set the values for tail->next (which is currently NULL) to src head

    // the address of ptr_DestTail should now be ptr_SrcHead
    *ptr_SrcHead = (*ptr_SrcHead)->next;
    (*ptr_DestTail)->next = NULL;*/
}

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE HEAD OF ANOTHER DECK
/// \param ptr_DestHead pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_SrcHead pointer containing the mem adr of the pointer to head deck to be inserted FROM
void insertAtHead(Card **ptr_SrcHead, Card **ptr_DestHead) {
    Card* tempPointer = (*ptr_SrcHead)->next; // saves the pointer to the pointer pointing to the next card after head1

    if(*ptr_DestHead == NULL) { // checks if the values at the address ptr_DestHead is pointing to are NULL
        *ptr_DestHead = *ptr_SrcHead;
        (*ptr_DestHead)->next = NULL;

    } else {
        (*ptr_SrcHead)->next = *ptr_DestHead;
        *ptr_DestHead = *ptr_SrcHead;
    }
    *ptr_SrcHead = tempPointer;

}

/// INSERTS THE CURRENT HEAD OF ONE DECK AT A GIVEN SPOT BETWEEN THE HEAD AND THE TAIL OF ANOTHER DECK
/// \param ptr_DestHead pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_DestTail pointer containing the mem adr of the pointer to tail of deck to be inserted TO
/// \param ptr_SrcHead pointer containing the mem adr of the pointer to head deck to be inserted FROM
/// \param numNodesToTraverse integer indicating how many Card nodes to traverse before inserting Card
void insertBetween(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail, int numNodesToTraverse) {
    Card* tempPointer = (*ptr_SrcHead)->next;
    Card* current = *ptr_DestHead;
    for(int i = 0 ; i < numNodesToTraverse ; i++) {
        current = current->next;
    }

    if (*ptr_DestHead == NULL || current->next == NULL) {
        insertAtTail(ptr_SrcHead, ptr_DestHead, ptr_DestTail);

    } else {

        (*ptr_SrcHead)->next = current->next;
        current->next = *ptr_SrcHead;
        *ptr_SrcHead = tempPointer;

    }
}

bool validateMoveToFoundation(Card** cardToBeMoved, Card** foundationTail) {
    char requiredSuit = (*foundationTail)->suit;
    if((*cardToBeMoved)->suit == requiredSuit || requiredSuit == ']') {
        char requiredRank;
        if((*foundationTail)->rank == '[') {
            requiredRank = 'A';

        } else if ((*foundationTail)->rank == 'A') {
            requiredRank = '2';

        } else if ((*foundationTail)->rank >= 50 && (*foundationTail)->rank <= 57) { // using ascii values of char to check condition
            requiredRank = ((*foundationTail)->rank) + 1;
            printf("requiredRank: %c\n", requiredRank);

        } else if ((*foundationTail)->rank == 'T') {
            requiredRank = 'J';

        } else if ((*foundationTail)->rank == 'J') {
            requiredRank = 'Q';

        } else if ((*foundationTail)->rank == 'Q') {
            requiredRank = 'K';

        } else {
            printf("Invalid rank at foundation tail.\n");
            return false;
        }

        if((*cardToBeMoved)->rank == requiredRank) {

            return true;

        } else {
            printf("Card to be moved does not have the correct rank!\n");
            return false;

        }

    } else {
        printf("Card to be moved does not have the correct suit!\n");
        return false;
    }

}

bool validateMoveToColumn(Card* src, Pile** destColumn) {
    char expectedRank;
    if((*destColumn)->tail->rank == 'A'){
        expectedRank = '2';

    } else if((*destColumn)->tail->rank >= 50 && (*destColumn)->tail->rank <= 57) { // using ascii values of char to check condition
        expectedRank = (*destColumn)->tail->rank+1;

    } else if ((*destColumn)->tail->rank == 'T') {
        expectedRank = 'J';

    } else if ((*destColumn)->tail->rank == 'J') {
        expectedRank = 'Q';

    } else if ((*destColumn)->tail->rank == 'Q') {
        expectedRank = 'K';

    } else {
        printf("Invalid rank at foundation tail.\n");
        return false;
    }


    if(src->rank == expectedRank){
        return true;

    } else {
        printf("The card %c%c is not the right value to be moved.\n",src->rank, src->suit);
        return false;
    }

}

void moveToColumn(Pile** src, Pile** destColumn, char cardToBeMovedRank){
    Pile* pileToBeMoved = (*src);
    while(pileToBeMoved->head->rank != cardToBeMovedRank) {
        pileToBeMoved->head = pileToBeMoved->head->next;
    }
    if(validateMoveToColumn(pileToBeMoved->head, destColumn)) {
        while(pileToBeMoved->head != NULL) {
            insertAtTail(&pileToBeMoved->head, &(*destColumn)->head, &(*destColumn)->tail);
        }

    } else {
        printf("Could not move card %c%c.\n", pileToBeMoved->head->rank, pileToBeMoved->head->suit);
    }
    //printf("current card is: %c%c", pileToBeMoved->head->rank, pileToBeMoved->head->suit);

}


