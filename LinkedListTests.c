//
// Created by Watson on 2023-05-06.
//

#include "headers/AllHeaders.h"

void testInsertAtTail(int repeats) {
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

    printf("\n");
    Card* destHead = NULL;
    Card* destTail = NULL;
    insertAtHead(&head, &destHead, &destTail);
    insertAtHead(&head, &destHead, &destTail);
    insertAtTail(&head, &destHead, &destTail);

    Card *current = destHead;
    while (current != NULL) {
        printf("%c%c ", current->rank, current->suit);
        current = current->next;
    }
}


