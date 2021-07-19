#include "death_angel_telephone_directory.h"
#include "death_angel_error.h"
#include "death_angel_read.h"

#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

int Free_List_Abonent(telephone_directory** list_abonent)
{
	telephone_directory* temp = *list_abonent;
	while(temp != NULL)
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