//
// Created by Watson on 2023-04-15.
//
#include <stdio.h>
#include "headers/AllHeaders.h"
#include <stdlib.h>

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE TAIL OF ANOTHER DECK
/// \param ptr_SrcHead pointer containing the mem adr of the pointer to head deck to be inserted FROM
/// \param ptr_DestHead pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_DestTail pointer containing the mem adr of the pointer to tail of deck to be inserted TO

void insertAtTail(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail) {
    if(*ptr_DestHead == NULL) { // if the values at ptr_DestHead are NULL
        *ptr_DestHead = *ptr_SrcHead;

    } else {(*ptr_DestTail)->next = *ptr_SrcHead; // or else set the pointer, pointing to destination tail, to point to the pointer to the source's head card
    }

    *ptr_DestTail = *ptr_SrcHead;// the pointer ptr_DestTail should now be pointing to the same as ptr_SrcHead
    if((*ptr_SrcHead)->next != NULL){
        *ptr_SrcHead = (*ptr_SrcHead)->next;
    } else {
        *ptr_SrcHead = NULL;
    }

    (*ptr_DestTail)->next = NULL;

}

/// INSERTS THE CURRENT HEAD OF ONE DECK AT THE HEAD OF ANOTHER DECK
/// \param ptr_DestHead pointer containing the mem adr of the pointer to head deck to be inserted TO
/// \param ptr_SrcHead pointer containing the mem adr of the pointer to head deck to be inserted FROM
void insertAtHead(Card **ptr_SrcHead, Card **ptr_DestHead, Card **ptr_DestTail) {
    Card* tempPointer = (*ptr_SrcHead)->next; // saves the pointer to the pointer pointing to the next card after SrcHead

    if(*ptr_DestHead == NULL) { // checks if the pointer pointing to the destination head card is NULL
        *ptr_DestHead = *ptr_SrcHead;
        (*ptr_DestHead)->next = NULL;
        *ptr_DestTail = *ptr_SrcHead;

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

/// FUNCTION TO MODIFY THE TAIL OF A GIVEN COLUMN (mainly used for moving cards away from a column)
/// \param columnToModify pointer to the pointer that points to the Pile struct of the column to modify
/// \param newTail pointer to the card which should be the new tail of the pile
void setNewTail(Pile** columnToModify, Card** newTail) {
    (*columnToModify)->tail = (*newTail);
    if((*newTail) != NULL) {
        (*columnToModify)->tail->next = NULL;
        if((*newTail)->isVisible == false){
            setVisibility(newTail, true);
        }
    } else {
        (*columnToModify)->head = NULL;
    }
}



/// FUNCTION TO VALIDATE, THAT MOVING A CARD A FOUNDATION PILE FOLLOWS THE RULES OF THE GAME
/// \param cardToBeMoved pointer to a pointer that points to the card that should be moved
/// \param foundationTail pointer to a pointer that points to the card sitting at the top of the foundation pile
/// \return true if valid, false if invalid
bool validateMoveToFoundation(char srcRank, char srcSuit, Card** foundationTail, char** ptrMessage) {

    if(*foundationTail == NULL) {
        if(srcRank == 'A') {
            return true;
        } else {
            return false;
        }

    } else {
        char rankOrder[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

        if(srcSuit != (*foundationTail)->suit) {
            setMessage(ptrMessage, "Card to be moved does not have the correct suit!\n");
            return false;
        } else {

            char requiredRank = rankOrder[12];
            printf("required rank before for loop: %c", requiredRank);
            for(int i = 0 ; i < 12 ; i++) {
                if((*foundationTail)->rank == rankOrder[i]){
                    requiredRank = rankOrder[i+1];
                    break;
                }

            }

            if(srcRank == requiredRank){
                return true;

            } else {
                setMessage(ptrMessage, "Card to be moved does not have the correct rank!\n");
                return false;
            }

        }

    }

}

/// FUNCTION TO VALIDATE THAT MOVING A/MANY CARDS TO ANOTHER COLUMN FOLLOWS THE RULES
/// \param srcRank char of the rank of the card to be moved
/// \param destColumn pointer to the pointer of the destination Pile
/// \param ptrMessage pointer to the char array that contains the message to display in user console
/// \return true if valid move, false if not valid
bool validateMoveToColumn(char srcRank, Pile **destColumn, char **ptrMessage) {
    char expectedRank;
    if ((*destColumn)->head == NULL) {
        return true;
    } else {
        if ((*destColumn)->tail->rank == 'A') {
            expectedRank = '2';

        } else if ((*destColumn)->tail->rank >= 50 &&
                   (*destColumn)->tail->rank < 57) { // using ascii values of char to check condition from rank 2 to 8
            expectedRank = (*destColumn)->tail->rank + 1;

        } else if ((*destColumn)->tail->rank == '9') {
            expectedRank = 'T';

        } else if ((*destColumn)->tail->rank == 'T') {
            expectedRank = 'J';

        } else if ((*destColumn)->tail->rank == 'J') {
            expectedRank = 'Q';

        } else if ((*destColumn)->tail->rank == 'Q') {
            expectedRank = 'K';

        } else if ((*destColumn)->tail->rank == 'K') {
            setMessage(ptrMessage, "Cannot add card after the King.");
            return false;

        } else {
            setMessage(ptrMessage, "Invalid rank.\n");

            return false;
        }


        if (srcRank == expectedRank) {
            return true;

        } else {
            setMessage(ptrMessage, "The card is not the right value to be moved.\n");

            return false;
        }

    }
}

/// FUNCTION TO MOVE MANY CARD(S) TO A COLUMN
/// \param src pointer to a pointer that points to Pile of cards to be moved
/// \param dest pointer to a pointer, pointing to the destination Pile (column)
/// \param cardToBeMovedRank rank of the card to be moved
void moveCards(Pile **src, Pile **dest, char cardToBeMovedRank, char cardToBeMovedSuit, char **ptrMessage) {
    Card* tempHead = (*src)->head;
    Card* newTail = NULL;
    while(tempHead->rank != cardToBeMovedRank || tempHead->suit != cardToBeMovedSuit) {
        newTail = tempHead;
        tempHead = tempHead->next;
    }

     if(newTail != NULL || (tempHead->rank == cardToBeMovedRank && tempHead->suit == cardToBeMovedSuit)) {
         switch((*dest)->type){
             case COLUMN:
                     while (tempHead != NULL) {
                         insertAtTail(&tempHead, &(*dest)->head, &(*dest)->tail);
                     }
                     setNewTail(src, &newTail);
                     setMessage(ptrMessage, "Move successful.");

                 break;

             case FOUNDATION:

                     insertAtTail(&tempHead, &(*dest)->head, &(*dest)->tail);
                     setNewTail(src, &newTail);
                     setMessage(ptrMessage, "Move successful.");

                 break;
             default:  setMessage(ptrMessage, "Invalid Pile type.");

         }

     } else {
         setMessage(ptrMessage, "Card not found in given column.");
     }

}
Move  *createMove(Pile **src , Pile **dest , char rank , char suit)
{
    Move *newMove = (Move*) malloc(sizeof (Move));
    //Move **head = &moveList;
    newMove->src = *src;
    newMove->dest = *dest;
    newMove->rank = rank;
    newMove->suit = suit;
    //newMove->prev = moveList->tail;
    newMove->prev = NULL;
    newMove->next = NULL;
    return newMove;
}

MoveList *createMoveList (Move** head){
    MoveList *newMoveList = (MoveList*) malloc(sizeof(MoveList));
    newMoveList->head = *head;
    newMoveList->tail = NULL;
    return newMoveList;
}
void AddMove (Pile **src , Pile **dest , char rank , char suit, MoveList **moveList){
    Move *newMove = createMove(src, dest, rank, suit);
    if((*moveList) == NULL) { // is the move list hasn't been created yet
        (*moveList) = createMoveList(&newMove);

    } else {
        (*moveList)->tail->next = newMove; // or else set the pointer, pointing to destination tail, to point to the pointer to the source's head card

    }
    Move* temp = (*moveList)->tail;
    (*moveList)->tail = newMove;// the pointer ptr_DestTail should now be pointing to the same as ptr_SrcHead
    (*moveList)->tail->prev = temp;
    (*moveList)->tail->next = NULL;

}
void undoLastMove(MoveList **moveList, char** ptrMessage){
    if((*moveList)->head == NULL) {
        setMessage(ptrMessage, "Nothing to undo! ");
    } else {
        // to traverse the list backwards to undo moves
        Move *lastMove = (*moveList)->tail;

        (*moveList)->tail = lastMove->prev;
        if ((*moveList)->tail != NULL) {
            (*moveList)->tail->next = NULL;
        } else {
            (*moveList)->head = NULL;
        }

        Pile *src = lastMove->src;
        Pile *dest = lastMove->dest;
        char rank = lastMove->rank;
        char suit = lastMove->suit;

        moveCards(&dest, &src, rank, suit, ptrMessage);
    }
}




