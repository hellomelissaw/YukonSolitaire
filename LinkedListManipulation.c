//
// Created by Watson on 2023-04-15.
//
#include <stdio.h>
#include "headers/AllHeaders.h"

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



