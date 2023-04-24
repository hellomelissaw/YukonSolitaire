//
// Created by Watson on 2023-04-24.
//
#include "Pile.c"
#include "LinkedListManipulation.c"
#include <stdio.h>

void testCreatingPile() {
    Card* head = createCard('A','C');
    Pile* testPile = createPile(head);
    printf("This is the head of the test pile : %c%c and this is the tail: %c%c upon creation.\nexpected head: AC, expected tail: AC",
           testPile->head->rank, testPile->head->suit, testPile->tail->rank, testPile->tail->suit);
}

void testAddingAtTailOfPile() {
    Card* head = createCard('A','C');
    Pile* testPile = createPile(head);
    Card* secondCard = createCard('2', 'C');

    insertAtTail(&secondCard, &testPile->head, &testPile->tail);
    printf("This is the head of the test pile : %c%c and this is the tail: %c%c after insert 2nd card.\nexpected head: AC, expected tail: 2C",
           testPile->head->rank, testPile->head->suit, testPile->tail->rank, testPile->tail->suit);

    Card* thirdCard = createCard('3', 'C');

    insertAtTail(&thirdCard, &testPile->head, &testPile->tail);
    printf("This is the head of the test pile : %c%c and this is the tail: %c%c after insert 3rd card.\nexpected head: AC, expected tail: 3C",
           testPile->head->rank, testPile->head->suit, testPile->tail->rank, testPile->tail->suit);

}

void testAccessingNextCard() {
    Card* head = createCard('A','C');
    Pile* testPile = createPile(head);
    Card* secondCard = createCard('2', 'C');

    insertAtTail(&secondCard, &testPile->head, &testPile->tail);
    Card* thirdCard = createCard('3', 'C');

    insertAtTail(&thirdCard, &testPile->head, &testPile->tail);
    printf("This is the head of the test pile : %c%c and this is the next card %c%c after insert 3rd card.\nexpected head: AC, expected next: 2C\n",
           testPile->head->rank, testPile->head->suit, testPile->head->next->rank, testPile->head->next->suit);
    printf("this is the next, next card: %c%c, after insert 3rd card.\n expected next next: 3C",
           testPile->head->next->next->rank, testPile->head->next->next->suit);
}
