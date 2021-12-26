#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 2
bool isOdd(int number)
{
	return number % 2 != 0;
}

int sumOddAboveMainDiagonal(int matrix[][MAX_SIZE], int n)
{
	int sum = 0;

	// поо редове, отдолу - нагоре, отляво - надясно  
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (isOdd(matrix[i][j]))
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    read(matrix, 4, 4);
	std::cout
		<< "Sum of odd elements above the main diagonal: "
		<< sumOddAboveMainDiagonal(matrix, 4) << std::endl;

    return 0;
}
