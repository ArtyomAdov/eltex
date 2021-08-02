#include "death_angel_division.h"

void Division_Two_Integer_Value(int* first_argument, int second_argument)
{
	if(0 != second_argument)
	{
		*first_argument = (*first_argument / second_argument);
	}
}