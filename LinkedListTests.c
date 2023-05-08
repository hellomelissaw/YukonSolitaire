//
// Created by Watson on 2023-05-06.
//

#include "headers/AllHeaders.h"

void testShuffleRandom5Cards(int repeats) {
    printf("\n\nRandomly shuffling 5 cards:\n");
    Card* head = createCard('8', 'H');
    head->next = createCard('K', 'D');
    head->next->next = createCard('4', 'H');
    head->next->next->next = createCard('3', 'C');
    head->next->next->next->next = createCard('2', 'H');
    head->next->next->next->next->next = NULL;

    for(int i = 0 ; i < repeats ; i++) {
        Card *newDeck = NULL;
        newDeck = shuffleRandom(head);
        head = newDeck;

        Card *current = head;
        while (current != NULL) {
            printf("%c%c ", current->rank, current->suit);
            current = current->next;
        }
        printf("\n");
    }
}

void testInsertAtHeadInsertAtTail() {
    Card* head = createCard('8', 'H');
    head->next = createCard('K', 'D');
    head->next->next = createCard('4', 'H');
    head->next->next->next = NULL;

    Card* destHead = NULL;
    Card* destTail = NULL;
    insertAtHead(&head, &destHead, &destTail);
    insertAtHead(&head, &destHead, &destTail);
    insertAtTail(&head, &destHead, &destTail);

    Card *current = destHead;
    printf("Test insert card at head twice then at tail\nExpected: KD 8H 4H, Actual: ");
    while (current != NULL) {
        printf("%c%c ", current->rank, current->suit);
        current = current->next;
    }
}

void testValidationMovingTenToNine () {
    char* testMessage = "Testing moving 10 to 9";
    Pile* testpile1 = createPile(COLUMN);
    Pile* testpile2 = createPile(COLUMN);

    Card* TWOS = createCard('2', 'S');
    Card* THREEH = createCard('3', 'H');
    Card* TS = createCard('T', 'S');
    Card* NH = createCard('9', 'H');

    testpile1->head = THREEH;
    testpile2->head = TWOS;

    testpile1->tail = NH;
    testpile2->tail = TS;

    bool valid = validateMoveToColumn(testpile2->tail->rank, &testpile1, &testMessage);
    printf("\nTesting validation of moving 10 to 9: \nExpected : 1 (true = 1), Actual: %d\n\n", valid);

}

//
// Created by Watson on 2023-04-24.
//
//#include <ctest.h>
#include "headers/AllHeaders.h"

void moveFirstCardToFoundationTest() {
    Pile** foundationPiles = setFoundationLists();
    Card* ac = createCard('A', 'C');
    if(validateMoveToFoundation(ac->rank, ac->suit, &foundationPiles[0]->tail, NULL)) {
      insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

    printf("\n\nTesting moving AC to an empty foundation pile: \nExpected: AC, Actual: %c%c", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);

}


void move2CToFoundationTest() {
    Pile** foundationPiles = setFoundationLists();
    Card* ac = createCard('A', 'C');
    Card* twoc = createCard('2', 'C');
    if(validateMoveToFoundation(ac->rank, ac->suit, &foundationPiles[0]->tail, NULL)) {
        insertAtTail(&ac, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }
    if(validateMoveToFoundation(twoc->rank, twoc->suit, &foundationPiles[0]->tail,NULL)) {
        insertAtTail(&twoc, &foundationPiles[0]->head, &foundationPiles[0]->tail);
    }

    printf("\n\nTesting moving AC to an empty foundation pile: \nExpected: AC, Actual: %c%c", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);
    printf("\n\nTesting moving 2C to foundation pile containing AC: \nExpected: 2C, Actual: %c%c", foundationPiles[0]->tail->rank, foundationPiles[0]->tail->suit);

}

void testMove2CAnd3CToColumnWithAS(){
    Card* as = createCard('A', 'S');
    Card* ac = createCard('A', 'C');
    Card* twoc = createCard('2', 'C');
    Card* threec = createCard('3', 'C');
    Pile* testColumn1 = createPile(COLUMN);
    Pile* testColumn2 = createPile(COLUMN);
    insertAtTail(&ac, &testColumn1->head, &testColumn1->tail);
    insertAtTail(&twoc, &testColumn1->head, &testColumn1->tail);
    insertAtTail(&threec, &testColumn1->head, &testColumn1->tail);
    insertAtTail(&as, &testColumn2->head, &testColumn2->tail);
    printf("testColumn1 tail before move expected 3C, actual : %c%c\n", testColumn1->tail->rank, testColumn1->tail->suit);
    printf("testColumn2 tail before move expected AS, actual : %c%c\n", testColumn2->tail->rank, testColumn2->tail->suit);

    moveCards(&testColumn1, &testColumn2, '2', 'C', NULL);

    printf("testColumn1 new tail expected: AC, actual: %c%c\n", testColumn1->tail->rank, testColumn1->tail->suit);
    printf("testColumn1 head expected after move: AC, actual: %c%c\n", testColumn1->head->rank, testColumn1->head->suit);
    printf("testColumn2 tail after move expected 3C, actual : %c%c\n", testColumn2->tail->rank, testColumn2->tail->suit);

}






