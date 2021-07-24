#include "death_angel_additional.h"
#include "death_angel_difference.h"
#include "death_angel_multiple.h"
#include "death_angel_division.h"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define KEY_CHOICE_ADDITIONAL '1'
#define KEY_CHOICE_DIFFERENCE '2'
#define KEY_CHOICE_MULTIPLE '3'
#define KEY_CHOICE_DIVISION '4'
#define KEY_CHOICE_CLEAR_SCREEN '9'
#define KEY_CHOICE_EXIT_FROM_PROGRAMM '0'

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
	int first_argument = 0;
	int second_argument = 0;
	char key_choice = '0';
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
				Additional_Two_Integer_Value(&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_DIFFERENCE):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				Difference_Two_Integer_Value(&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_MULTIPLE):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				Multiple_Two_Integer_Value(&first_argument, second_argument);
				printf("Result: %d\n", first_argument);
				break;
			}
			case(KEY_CHOICE_DIVISION):
			{
				printf("Write First Argument\n");
				scanf("%d", &first_argument);
				printf("Write Second Argument\n");
				scanf("%d", &second_argument);
				Division_Two_Integer_Value(&first_argument, second_argument);
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