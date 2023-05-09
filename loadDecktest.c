//
// Created by Sabirin on 09/05/2023.
//
#include "headers/AllHeaders.h"


int loadDeckTest() {
    FILE *fptr;

    char filename[100], c;

    printf("Enter the filename to open \n");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}



