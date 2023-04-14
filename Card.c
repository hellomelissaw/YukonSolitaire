//
// Created by Watson on 2023-04-14.
//
#include <stdbool.h>

typedef struct Card
{
    char rank;
    char suit;
    struct Card *next;
    bool isVisible;

} Card;