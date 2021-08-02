#include <dirent.h>
#include <dlfcn.h>
#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define KEY_CHOICE_ADDITIONAL '1'
#define KEY_CHOICE_DIFFERENCE '2'
#define KEY_CHOICE_MULTIPLE '3'
#define KEY_CHOICE_DIVISION '4'
#define KEY_CHOICE_CLEAR_SCREEN '9'
#define KEY_CHOICE_EXIT_FROM_PROGRAMM '0'

#define ERROR_OPEN_LIBRARY 0b10000001
#define ERROR_ALLOCATION_MEMORY 0b00000010
#define ERROR_UNKNOWN_FUNCTION 0b00000100

#define MAX_LENGTH_FULL_NAME_LIBRARY 150

void Print_Menu()
{
	printf("%c) Additional Two Integer Value\n", KEY_CHOICE_ADDITIONAL);
	printf("%c) Difference Two Integer Value\n", KEY_CHOICE_DIFFERENCE);
	printf("%c) Multiple Two Integer Value\n", KEY_CHOICE_MULTIPLE);
	printf("%c) Division Two Integer Value\n", KEY_CHOICE_DIVISION);
	printf("%c) Clear Screen\n", KEY_CHOICE_CLEAR_SCREEN);
	printf("%c) Exit From Programm\n", KEY_CHOICE_EXIT_FROM_PROGRAMM);
}

int main()
{
	DIR* library_directory = NULL;
	struct dirent* data_directory = NULL;
	void (**array_pointer_function)(int*, int);
	char* full_name_library = (char*)calloc(MAX_LENGTH_FULL_NAME_LIBRARY, sizeof(char));
	char* temp = (char*)calloc(MAX_LENGTH_FULL_NAME_LIBRARY, sizeof(char));
	void* handle = NULL;
	int first_argument = 0;
	int second_argument = 0;
	char key_choice = '0';
	array_pointer_function = (void (**)(int*, int))malloc(4 * sizeof(int*));
	if(NULL == array_pointer_function)
	{
		return ERROR_ALLOCATION_MEMORY;
	}
	if(NULL == full_name_library)
	{
		return ERROR_ALLOCATION_MEMORY;
	}
	if(NULL == temp)
	{
		return ERROR_ALLOCATION_MEMORY;
	}
	getcwd(full_name_library, MAX_LENGTH_FULL_NAME_LIBRARY);
	strcat(full_name_library, "/library");
	library_directory = opendir(full_name_library);
	strcat(full_name_library, "/");
	strcpy(temp, full_name_library);
	do
	{
		data_directory = readdir(library_directory);
		if(NULL == data_directory)
		{
			break;
		}
		if(NULL != strstr(data_directory->d_name, ".so"))
		{
			strcat(full_name_library, data_directory->d_name);
			handle = dlopen(full_name_library, RTLD_NOW);
			strcpy(full_name_library, temp);
			if(NULL == handle)
			{
				return ERROR_OPEN_LIBRARY;
			}
			if(strstr(data_directory->d_name, "additional"))
			{
				array_pointer_function[0] = dlsym(handle, "Additional_Two_Integer_Value");
			}
			else
			{
				if(strstr(data_directory->d_name, "difference"))
				{
					array_pointer_function[1] = dlsym(handle, "Difference_Two_Integer_Value");
				}
				else
				{
					if(strstr(data_directory->d_name, "multiple"))
					{
						array_pointer_function[2] = dlsym(handle, "Multiple_Two_Integer_Value");
					}
					else
					{
						if(strstr(data_directory->d_name, "division"))
						{
							array_pointer_function[3] = dlsym(handle, "Division_Two_Integer_Value");
						}
					}
				}
			}
		}
	} while(1);
	do
	{
		Print_Menu();
		read(STDIN_FILENO, &key_choice, sizeof(char));
		tcflush(STDIN_FILENO, TCIFLUSH);
		switch(key_choice)
		{
			case(KEY_CHOICE_ADDITIONAL):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				array_pointer_function[0](&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_DIFFERENCE):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				array_pointer_function[1](&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_MULTIPLE):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				array_pointer_function[2](&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_DIVISION):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				array_pointer_function[3](&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
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
	} while(KEY_CHOICE_EXIT_FROM_PROGRAMM != key_choice);
	return 0;
}