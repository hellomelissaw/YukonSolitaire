//
// Created by Watson on 2023-04-28.
//
#include "headers/AllHeaders.h"

void testPrintMessage() {

   char *message = "First message";
    char **messagePtr = &message;
    printf("%s", message);
    setMessage(messagePtr, "Second message");
    printf("%s", message);
}
