#include "algorithms.h"
#include "io.h"

#include <iostream>

int countDistinct(int array[], int n)
{
	int distinct[MAX_SIZE];
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (!isMember(distinct, count, array[i]))
		{
			distinct[count] = array[i];
			++count;
		}
	}

	return count;
}

void showRowsWithDistinctElements(int matrix[][MAX_SIZE], int n, int m, int maxCount)
{
	for (int i = 0; i < n; ++i)
	{
		int distinct = countDistinct(matrix[i], m);
		if (distinct < maxCount)
		{
			sort(matrix[i], m);
			print(matrix[i], m);
		}
	}
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
	read(matrix, 4, 5);
	showRowsWithDistinctElements(matrix, 4, 5, 5);

    return 0;
}
