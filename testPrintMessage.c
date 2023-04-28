//
// Created by Watson on 2023-04-28.
//
#include <stdlib.h>
#include <string.h>
#include "headers/AllHeaders.h"


void testPrintMessage() {
    char *message = "First message";
    char **messagePtr = &message;
    printf("%s", message);

    char *newMessage = malloc(100);

    strcpy(newMessage, "Second message");
    setMessage(messagePtr, newMessage);
    printf("%s", message);
}