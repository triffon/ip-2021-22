#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 4
void deleteRow(int matrix[][MAX_SIZE], int& rows, int cols, int k)
{
	if (k < 0 || k >= rows)
		return;

	for (int i = k; i < rows - 1; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = matrix[i + 1][j];
		}
	}

	--rows;
}


int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
	int rows = 4;
	int cols = 5;

    read(matrix, rows, cols);
	deleteRow(matrix, rows, cols, 1);
	printByRows(matrix, rows, cols);

    return 0;
}
