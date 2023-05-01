//
// Created by Admin on 28/04/2023.
//

#ifndef YUKONSOLITAIRE_LOADDECK_H
#define YUKONSOLITAIRE_LOADDECK_H

int is_valid_card(char* rank, char* suit);
int load_DefaultDeckLDCommand();
bool file_exists(const char *filename);
int load_SpecificFileIntoDeck(char *filename);
#endif //YUKONSOLITAIRE_LOADDECK_H
