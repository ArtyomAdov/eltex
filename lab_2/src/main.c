#include <stdio.h>

#define SIZE_ROW 5
#define SIZE_COLUMN 5
#define SIZE_ARRAY 5

void Print_Array(int array[], int size)
{
	printf("array:\n");
	for(short int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Fill_Increment_Array(int array[], int size)
{
	for(short int i = 0; i < size; i++)
	{
		array[i] = i;
	}
}

void Print_Square_Matrix(int matrix[SIZE_ROW][SIZE_COLUMN], int length_matrix, int width_matrix)
{
	printf("square matrix:\n");
	for(short int i = 0; i < length_matrix; i++)
	{
		for(short int j = 0; j < width_matrix; j++)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Fill_Increment_Square_Matrix(int matrix[SIZE_ROW][SIZE_COLUMN], int length_matrix, int width_matrix)
{
	for(short int i = 0; i < length_matrix; i++)
	{
		for(short int j = 0; j < width_matrix; j++)
		{
			matrix[i][j] = (i * width_matrix + j);
		}
	}
}

void Inverse_Array(int array[], int size)
{
	int temp = 0;
	for(short int i = 0, j = (size - 1); i != j; i++, j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void Fill_Zero_Square_Matrix(int matrix[SIZE_ROW][SIZE_COLUMN], int length_matrix, int width_matrix)
{
	for(short int i = 0; i < length_matrix; i++)
	{
		for(short int j = 0; j < width_matrix; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Fill_Unit_Up_Triangle(int matrix[SIZE_ROW][SIZE_COLUMN], int length_matrix, int width_matrix)
{
	for(short int i = 0; i < length_matrix; i++)
	{
		width_matrix--;
		for(short int j = 0; j < width_matrix; j++)
		{
			matrix[i][j] = 1;
		}
	}
}

void Fill_Increment_Square_Matrix_By_Spiral(int matrix[SIZE_ROW][SIZE_COLUMN], int length_matrix, int width_matrix)
{
	int size_matrix = (length_matrix * width_matrix);
	int start_row = 0;
	int start_column = 0;
	int value_element = 0;
	do
	{
		for(short int j = start_column; j < width_matrix; j++)
		{
			value_element++;
			matrix[start_row][j] = value_element;
		}
		width_matrix--;
		length_matrix--;
		start_row++;
		for(short int i = start_row; i < length_matrix; i++)
		{
			value_element++;
			matrix[i][width_matrix] = value_element;
		}
		for(short int j = width_matrix; j > start_column; j--)
		{
			value_element++;
			matrix[length_matrix][j] = value_element;
		}
		for(short int i = length_matrix; i > (start_row - 1); i--)
		{
			value_element++;
			matrix[i][start_column] = value_element;
		}
		start_column++;
	} while(value_element < size_matrix);
}

int main()
{
	int square_matrix[SIZE_ROW][SIZE_COLUMN];
	int array[SIZE_ARRAY];
	//task 1
	Fill_Increment_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	Print_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	//task 2
	Fill_Increment_Array(array, SIZE_ARRAY);
	Print_Array(array, SIZE_ARRAY);
	Inverse_Array(array, SIZE_ARRAY);
	Print_Array(array, SIZE_ARRAY);
	//task 3
	Fill_Zero_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	Fill_Unit_Up_Triangle(square_matrix, SIZE_ROW, SIZE_COLUMN);
	Print_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	//task 4
	Fill_Zero_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	Fill_Increment_Square_Matrix_By_Spiral(square_matrix, SIZE_ROW, SIZE_COLUMN);
	Print_Square_Matrix(square_matrix, SIZE_ROW, SIZE_COLUMN);
	return 0;
}