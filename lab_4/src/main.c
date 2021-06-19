#include <stdio.h>

#include <stdio.h>

#define QUANTITY_ABONENT 10
#define MAX_LENGTH_NAME 5
#define MAX_LENGTH_SURNAME 7

#define KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY '2'
#define KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY '3'
#define KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY '4'
#define KEY_CHOICE_CLEAR_SCREEN '9'
#define KEY_CHOICE_EXIT_FROM_PROGRAMM '0'

struct Telephone_Directory
{
	char name[MAX_LENGTH_NAME];
	char surname[MAX_LENGTH_SURNAME];
	int number_telephone;
};

typedef struct Telephone_Directory telephone_directory;

void Print_Menu()
{
	printf("%c) Find Note In Telephone Directory\n", KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY);
	printf("%c) Print Telephone Directory\n", KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY);
	printf("%c) Delete Note From Telephone Directory\n", KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY);
	printf("%c) Clear Screen\n", KEY_CHOICE_CLEAR_SCREEN);
	printf("%c) Exit From Programm\n", KEY_CHOICE_EXIT_FROM_PROGRAMM);
}

void Fill_Telephone_Directory(telephone_directory array_abonent[QUANTITY_ABONENT])
{
	for(short int i = 0; i < QUANTITY_ABONENT; i++)
	{
		for(short int j = 0; j < MAX_LENGTH_NAME - 1; j++)
		{
			array_abonent[i].name[j] = ('A' + i); 
		}
		array_abonent[i].name[MAX_LENGTH_NAME - 1] = '\0';
		for(short int j = 0; j < MAX_LENGTH_SURNAME - 1; j++)
		{
			array_abonent[i].surname[j] = ('a' + i);
		}
		array_abonent[i].surname[MAX_LENGTH_SURNAME - 1] = '\0';
		array_abonent[i].number_telephone = (1000 + i);
	}
}

void Print_Telephone_Directory(telephone_directory array_abonent[QUANTITY_ABONENT])
{
	for(short int i = 0; i < QUANTITY_ABONENT; i++)
	{
		printf("%d) %s  %s  %d\n", i, array_abonent[i].name, array_abonent[i].surname, array_abonent[i].number_telephone);
	}
	printf("\n");
}

void Delete_Note_From_Telephone_Directory(telephone_directory array_abonent[QUANTITY_ABONENT])
{
	int number_delete_note = 0;
	printf("write number delete note\n");
	scanf("%d", &number_delete_note);
	for(short int i = 0; i < MAX_LENGTH_NAME; i++)
	{
		array_abonent[number_delete_note].name[i] = 0;
	}
	for(short int i = 0; i < MAX_LENGTH_SURNAME; i++)
	{
		array_abonent[number_delete_note].surname[i] = 0;
	}
	array_abonent[number_delete_note].number_telephone = 0;
}

void Find_Note_In_Telephone_Directory(telephone_directory array_abonent[QUANTITY_ABONENT])
{
	int number_telephone_for_find = 0;
	printf("write number telephone find note\n");
	scanf("%d", &number_telephone_for_find);
	for(short int i = 0; i < QUANTITY_ABONENT; i++)
	{
		if(number_telephone_for_find == array_abonent[i].number_telephone)
		{
			printf("%d) %s\t%s\t%d\n", i, array_abonent[i].name, array_abonent[i].surname, array_abonent[i].number_telephone);
			break;
		}
	}
}

int main()
{
	telephone_directory array_abonent[QUANTITY_ABONENT];
	char key_choice = '0';
	Fill_Telephone_Directory(array_abonent);
	Print_Telephone_Directory(array_abonent);
	Print_Menu();
	do
	{
		scanf("%c", &key_choice);
		switch(key_choice)
		{
			case(KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY):
			{
				Find_Note_In_Telephone_Directory(array_abonent);
				Print_Menu();
				break;
			}
			case(KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY):
			{
				Print_Telephone_Directory(array_abonent);
				Print_Menu();
				break;
			}
			case(KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY):
			{
				Delete_Note_From_Telephone_Directory(array_abonent);
				Print_Menu();
				break;
			}
			case(KEY_CHOICE_CLEAR_SCREEN):
			{
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				Print_Menu();
				break;
			}
			default:
			{
				break;
			}
		}
	}while(key_choice != '0');
	return 0;
}