//
// Created by Mélissa on 2023-04-03.
//
# include <stdio.h>

int shuffleInterweave() {
    // OPEN A FILE USING READ-MODE "r"
    FILE * fpointer = fopen("cards.txt", "r");

    // STORE CONTENTS OF THE FILE IN A STRING
    char cards[157];

    // READ CONTENTS OF FILE (1ST PARAM IS DEST, 2ND MAX DATA SIZE, POINTER TO FILE TO BE READ)
    fgets(cards, 157, fpointer);

    printf("s%",cards);

    fclose(fpointer);
}
