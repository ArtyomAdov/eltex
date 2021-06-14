#include <stdio.h>

#define START_HEXADECIMAL_VALUE 0x00DDAABB
#define VALUE_FOR_SAVE_LAST_BYTE 0x000000FF
#define START_NEW_VALUE_BYTE 0x000000EE

#define START_NUMBER_CHANGE_BYTE 2
#define QUANTITY_BYTE_IN_INTEGER_VALUE 4
#define QUANTITY_SHIFT_BIT_FOR_MULTIPLE_EIGHT 3

void Print_Integer_Value_By_Bytes(int integer_value)
{
    int value_one_byte = 0b0;
    for(short int i = 0; i < QUANTITY_BYTE_IN_INTEGER_VALUE; i++)
    {
        value_one_byte = ((integer_value >> (i << QUANTITY_SHIFT_BIT_FOR_MULTIPLE_EIGHT)) & VALUE_FOR_SAVE_LAST_BYTE);
        printf("%d) %02X\n", i, value_one_byte);
    }
}

void Change_Choice_Byte(int* integer_value, int new_value_byte, int number_change_byte)
{
    int temp = 0;
    temp = ~(VALUE_FOR_SAVE_LAST_BYTE << (number_change_byte << QUANTITY_SHIFT_BIT_FOR_MULTIPLE_EIGHT));
    *integer_value = (*integer_value & temp);
    temp = (new_value_byte << (number_change_byte << QUANTITY_SHIFT_BIT_FOR_MULTIPLE_EIGHT));
    *integer_value = (*integer_value | temp);
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