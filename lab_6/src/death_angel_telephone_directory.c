#include "death_angel_telephone_directory.h"
#include "death_angel_error.h"
#include "death_angel_read.h"

#include <malloc.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int Free_List_Abonent(telephone_directory** list_abonent)
{
	telephone_directory* temp = *list_abonent;
	while(NULL != temp)
	{
		free(temp->data_abonent.surname);
		free(temp->data_abonent.name);
		*list_abonent = (*list_abonent)->next_abonent;
		free(temp);
		temp = *list_abonent;
	}
	return 0;
}

int Add_Note_In_Telephone_Directory(telephone_directory** list_abonent)
{
	telephone_directory* temp = NULL;
	temp = (telephone_directory*)malloc(sizeof(telephone_directory));
	if(NULL == temp)
	{
		return ERROR_ALLOCATION_MEMORY;
	}
	printf("Write Surname\n");
	CHECK_ERROR_FLAG(Get_Dynamic_User_Input_String(&temp->data_abonent.surname, &temp->data_abonent.size_surname));
	printf("Write Name\n");
	CHECK_ERROR_FLAG(Get_Dynamic_User_Input_String(&temp->data_abonent.name, &temp->data_abonent.size_name));
	printf("Write Telephone Number\n");
	Get_Static_User_Input_String(temp->data_abonent.telephone_number);
	temp->next_abonent = *list_abonent;
	*list_abonent = temp;
	return 0;
}

int Find_Note_In_Telephone_Directory_By_Telephone_Number(telephone_directory* list_abonent)
{
	telephone_directory* temp = list_abonent;
	char user_input_string[11] = {'0'};
	int counter_abonent = 0;
	char find_flag = FLAG_VALUE_FIND_NOTE;
	Get_Static_User_Input_String(user_input_string);
	while(NULL != temp)
	{
		counter_abonent++;
		for(short int i = 0; i < MAX_LENGTH_TELEPHONE_NUMBER; i++)
		{
			if(user_input_string[i] != temp->data_abonent.telephone_number[i])
			{
				find_flag = !(FLAG_VALUE_FIND_NOTE);
				break;
			}
		}
		if(FLAG_VALUE_FIND_NOTE == find_flag)
		{
			printf("%d) %s %s %s\n", counter_abonent, temp->data_abonent.surname, temp->data_abonent.name, temp->data_abonent.telephone_number);
			return 0;
		}
		find_flag = FLAG_VALUE_FIND_NOTE;
		temp = temp->next_abonent;
	}
	printf("Need Note Not Found\n");
	return 0;
}

int Delete_Note_From_Telephone_Directory_By_Number_Note(telephone_directory** list_abonent)
{
	telephone_directory* temp_current = *list_abonent;
	telephone_directory* temp_previos = *list_abonent;
	int number_delete_note = 0;
	int counter_abonent = 1;
	scanf("%d", &number_delete_note);
	tcflush(STDIN_FILENO, TCIFLUSH);
	if(NULL == *list_abonent)
	{
		printf("Telephone Directory Is Empty\n");
		return 0;
	}
	if(1 == number_delete_note)
	{
		*list_abonent = (*list_abonent)->next_abonent;
		free(temp_current->data_abonent.surname);
		free(temp_current->data_abonent.name);
		free(temp_current);
		return 0;
	}
	temp_current = temp_current->next_abonent;
	while(NULL != temp_current)
	{
		counter_abonent++;
		if(counter_abonent == number_delete_note)
		{
			temp_previos->next_abonent = temp_current->next_abonent;
			free(temp_current->data_abonent.surname);
			free(temp_current->data_abonent.name);
			free(temp_current);
			return 0;
		}
		temp_previos = temp_current;
		temp_current = temp_current->next_abonent;
	}
	printf("Need Note Not Found\n");
	return 0;
}