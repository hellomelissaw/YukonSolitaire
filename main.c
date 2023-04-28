//#include "Shuffle.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Board.c"
#include "headers/Utilities.h"
//#include "loadDeck.c"
/*int main() {

    //createDeck("unshuffledCards.txt");
    printDeck(shuffleInterweave(13,createDeck("unshuffledCards.txt")));

#include "Board.c"
int main(void) {
    printBoard("unshuffledCards.txt");

}
 */


int load_DefaultDeckLDCommand() {
    FILE *fp;
    char str[100];

    /* opening file for reading */

    char* abspath = getAbs_path("defaultDeckOfCards");
    fp = fopen(abspath, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }


    printBoard(abspath);
    fclose(fp);
    return 0;

}
// return true if the file specified by the filename exists
bool file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL) {
        // check if we can read from the file
        if (fgetc(fp) != EOF) {
            is_exist = true;
        }
        fclose(fp); // close the file
    }
    return is_exist; //else not true, does not exist.
}


int load_SpecificFileIntoDeck(char *filename) {
    char c;
    char count;
    char countFileLine;
    filename[strcspn(filename, "\n")] = '\0';
    char* abs_path = getAbs_path(filename);
    FILE *file = fopen(abs_path, "r"); // open file in read mode
    if (file_exists(filename) || file != NULL) {
        //printf("File %s exists", filename);
        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                count++;
            }
        }

        if (countFileLine == 52) {
            char line[3]; // allocate space for each line
            while (fgets(line, sizeof(line), file)) {
                if (strlen(line) == 2) {
                    countFileLine++;
                }
            }
            fclose(file);
        } else {
            printf("The file does not have 52 lines.");
        }

    } else
        printf("File %s doesn't exist.", filename);

    return 0;
}


// Hey girl hey
int main() {
    char input[2];
    char str[100];
    char result[100];
    int length;

    while (1) {

        printf("\tC1   \tC2  \tC3  \tC4  \tC5  \tC6  \tC7");
        printf("\n");
        printf("                                                           []  \tF1\n");
        printf("                                                           []  \tF2\n");
        printf("                                                           []  \tF3\n");
        printf("                                                           []  \tF4\n");

        printf("");
        printf("LAST command; \n"); //add func
        printf("Message \n"); //add func
        printf("INPUT >");

        scanf("%s", &input);


        if (!strcmp(input, "QQ")) {
            printf("Quitting The Game");
            exit(0);
        }
        if (!strcmp(input, "LD")) {
            fgets(str, 100, stdin);
            length = strlen(str);

            printf("Length of |%s| is |%d|\n", str, length);

            if (length == 1) {
                printf("vi er her");
                load_DefaultDeckLDCommand();


            } else if (length > 1) {

                strcpy(result, str + 1);

                printf("Result: %s\n", result);
                load_SpecificFileIntoDeck(result);
            }
        }

        // FUNC here
    }
}
