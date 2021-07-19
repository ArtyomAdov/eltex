#include "death_angel_print.h"
#include "death_angel_telephone_directory.h"

#include <stdio.h>

void Print_Menu()
{
	printf("%c) Add Note In Telephone Directory\n", KEY_CHOICE_ADD_NOTE_IN_TELEPHONE_DIRECTORY);
	printf("%c) Find Note In Telephone Directory By Telephone Number\n", KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY_BY_TELEPHONE_NUMBER);
	printf("%c) Print Telephone Directory\n", KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY);
	printf("%c) Delete Note From Telephone Directory\n", KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY_BY_NUMBER_NOTE);
	printf("%c) Clear Screen\n", KEY_CHOICE_CLEAR_SCREEN);
	printf("%c) Exit From Programm\n", KEY_CHOICE_EXIT_FROM_PROGRAMM);
}

void Print_Telephone_Directory(telephone_directory* list_abonent)
{
	telephone_directory* temp = NULL;
	int counter_abonent = 0;
	printf("\n");
	if(NULL == list_abonent)
	{
		printf("Abonent Directory Is Empty\n\n");
		return (void)NULL;
	}
	temp = list_abonent;
	do
	{
		counter_abonent++;
		printf("%d) %s %s %s\n", counter_abonent, temp->data_abonent.surname, temp->data_abonent.name, temp->data_abonent.telephone_number);
		temp = temp->next_abonent;
	} while(NULL != temp);
	printf("\n\n");
}