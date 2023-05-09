//
// Created by Sabirin on 28/04/2023.
//

#ifndef YUKONSOLITAIRE_LOADDECK_H
#define YUKONSOLITAIRE_LOADDECK_H

int is_valid_card(char* rank, char* suit);
Card* load_DefaultDeckLDCommand(char** ptrMessage);
bool file_exists(const char *filename);
Card * load_SpecificFileIntoDeck(char *filename, char** ptrMessage);
#endif //YUKONSOLITAIRE_LOADDECK_H
