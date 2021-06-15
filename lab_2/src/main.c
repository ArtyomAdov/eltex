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
			printf("%2d ",matrix[i][j]);
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
	
	return 0;
}