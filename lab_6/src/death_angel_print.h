#ifndef DEATH_ANGEL_PRINT_H

#define DEATH_ANGEL_PRINT_H

#include "death_angel_telephone_directory.h"

#define KEY_CHOICE_ADD_NOTE_IN_TELEPHONE_DIRECTORY '1'
#define KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY '2'
#define KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY '3'
#define KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY '4'
#define KEY_CHOICE_CLEAR_SCREEN '9'
#define KEY_CHOICE_EXIT_FROM_PROGRAMM '0'

void Print_Menu();
void Print_Telephone_Directory(telephone_directory* list_abonent);

#endif