#include "Deck.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#include "loadDeck.c"
/*int main() {

    //createDeck("unshuffledCards.txt");
    printDeck(shuffleInterweave(13,createDeck("unshuffledCards.txt")));


}
 */


int load_DefaultDeckLDCommand() {
    FILE *fp;
    char str[60];

    /* opening file for reading */
    fp = fopen("defaultDeckOfCards", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(str, 60, fp) != NULL) {
        printf("%s", str);
        //STORE IN LINKEDLIST.
    }
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
    return is_exist; //else not true, doesnt exist.
}


int load_SpecificFileIntoDeck(char *filename) {
    char c;
    char count;
    char countFileLine;
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r"); // open file in read mode
    if (file_exists(filename) || file != NULL) {
        //printf("File %s exists", filename);
        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                count++;
            }
        }
        fclose(file);
        if (countFileLine == 52) {
            char line[3]; // allocate space for each line
            while (fgets(line, sizeof(line), file)) {
                if (strlen(line) == 2) {
                    countFileLine++;
                }
            }

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

            if (length == 2) {
                load_DefaultDeckLDCommand();

            } else if (length > 2) {

                strcpy(result, str + 1);

                printf("Result: %s\n", result);
                load_SpecificFileIntoDeck(result);
            }
        }
    }
}
