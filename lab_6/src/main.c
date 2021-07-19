#include "death_angel_error.h"
#include "death_angel_print.h"
#include "death_angel_read.h"
#include "death_angel_telephone_directory.h"

#include <malloc.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main()
{
	telephone_directory* list_abonent = NULL;
	char key_choice = '0';
	do
	{
		Print_Menu();
		read(STDIN_FILENO, &key_choice, sizeof(char));
		tcflush(STDIN_FILENO, TCIFLUSH);
		switch(key_choice)
		{
			case(KEY_CHOICE_ADD_NOTE_IN_TELEPHONE_DIRECTORY):
			{
				CHECK_ERROR_FLAG(Add_Note_In_Telephone_Directory(&list_abonent));
				break;
			}
			case(KEY_CHOICE_FIND_NOTE_IN_TELEPHONE_DIRECTORY_BY_TELEPHONE_NUMBER):
			{
				Find_Note_In_Telephone_Directory_By_Telephone_Number(list_abonent);
				break;
			}
			case(KEY_CHOICE_PRINT_TELEPHONE_DIRECTORY):
			{
				Print_Telephone_Directory(list_abonent);
				break;
			}
			case(KEY_CHOICE_DELETE_NOTE_FROM_TELEPHONE_DIRECTORY_BY_NUMBER_NOTE):
			{
				CHECK_ERROR_FLAG(Delete_Note_From_Telephone_Directory_By_Number_Note(&list_abonent));
				break;
			}
			case(KEY_CHOICE_CLEAR_SCREEN):
			{
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				break;
			}
			default:
			{
				break;
			}
		}
	} while(key_choice != '0');
	Free_List_Abonent(&list_abonent);
	return 0;
}