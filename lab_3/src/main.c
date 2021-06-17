#include <stdio.h>

#define ERROR_INCORRECT_NUMBER_BYTE 0b00000001

#define START_HEXADECIMAL_VALUE 0x00DDAABB
#define VALUE_FOR_SAVE_LAST_BYTE 0x000000FF
#define START_NEW_VALUE_BYTE 0x000000EE

#define START_NUMBER_CHANGE_BYTE 2
#define QUANTITY_BYTE_IN_INTEGER_VALUE 4
#define QUANTITY_SHIFT_BIT_FOR_MULTIPLE_EIGHT 3

#define CHECK_ERROR_FLAG(error_flag)           \
	{                                          \
		if(error_flag != 0b0)                  \
		{                                      \
			printf("Error: %d\n", error_flag); \
			return error_flag;                 \
		}                                      \
	}

void Print_Integer_Value_By_Bytes(int integer_value)
{
	unsigned char* pointer_one_byte = NULL;
	pointer_one_byte = (unsigned char*)&integer_value;
	printf("0) %2X\n", *pointer_one_byte);
	for(short int i = 1; i < QUANTITY_BYTE_IN_INTEGER_VALUE; i++)
	{
		pointer_one_byte++;
		printf("%d) %2X\n", i, *pointer_one_byte);
	}
	pointer_one_byte = NULL;
}

int Change_Choice_Byte(int* integer_value, int new_value_byte, int number_change_byte)
{
	unsigned char* pointer_one_byte = NULL;
	if(number_change_byte < 0 || number_change_byte > 3)
	{
		return ERROR_INCORRECT_NUMBER_BYTE;
	}
	pointer_one_byte = (unsigned char*)&(*integer_value);
	pointer_one_byte = (pointer_one_byte + number_change_byte);
	*pointer_one_byte = new_value_byte;
	pointer_one_byte = NULL;
	return 0;
}

int main()
{
	int integer_value = START_HEXADECIMAL_VALUE;
	printf("default value:\n");
	Print_Integer_Value_By_Bytes(integer_value);
	CHECK_ERROR_FLAG(Change_Choice_Byte(&integer_value, START_NEW_VALUE_BYTE, START_NUMBER_CHANGE_BYTE));
	printf("new value:\n");
	Print_Integer_Value_By_Bytes(integer_value);
	return 0;
}