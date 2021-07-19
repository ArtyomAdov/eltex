#include "death_angel_read.h"
#include "death_angel_error.h"
#include "death_angel_telephone_directory.h"

#include <malloc.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int Get_Dynamic_User_Input_String(char* user_input_string[], int* size_user_input_string)
{
	int i = -1;
	*size_user_input_string = 0;
	do
	{
		i++;
		if(*size_user_input_string == i)
		{
			*size_user_input_string = (*size_user_input_string + STEP_FOR_SIZE_USER_INPUT_STRING);
			*user_input_string = (char*)realloc(*user_input_string, *size_user_input_string * sizeof(char));
			if(NULL == *user_input_string)
			{
				return ERROR_ALLOCATION_MEMORY;
			}
		}
		read(STDIN_FILENO, &((*user_input_string)[i]), sizeof(char));
	} while('\n' != (*user_input_string)[i]);
	tcflush(STDIN_FILENO, TCIFLUSH);
	(*user_input_string)[i] = '\0';
	*size_user_input_string = (i + 1);
	*user_input_string = (char*)realloc(*user_input_string, *size_user_input_string * sizeof(char));
	return 0;
}

int Get_Static_User_Input_String(char user_input_string[MAX_LENGTH_TELEPHONE_NUMBER])
{
	read(STDIN_FILENO, &(*user_input_string), (MAX_LENGTH_TELEPHONE_NUMBER * sizeof(char)));
	tcflush(STDIN_FILENO, TCIFLUSH);
	for(short int i = 0; i < MAX_LENGTH_TELEPHONE_NUMBER; i++)
	{
		if((user_input_string[i] < FIRST_SYMBOL_DIGIT) || (user_input_string[i] > LAST_SYMBOL_DIGIT))
		{
			for(short int j = i; j < MAX_LENGTH_TELEPHONE_NUMBER; j++)
			{
				user_input_string[j] = '\0';
			}
			break;
		}
	}
	return 0;
}