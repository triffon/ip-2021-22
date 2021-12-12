#include <iostream>

const int MAX_SIZE = 10;

void readRow(int row[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> row[i];
	}
}

void printRow(int row[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << row[i] << ' ';
	}
}

void readMatrix(int m[][MAX_SIZE], int rows, int cols)
{
	for (int currentRow = 0; currentRow < rows; ++currentRow)
	{
		readRow(m[currentRow], cols);
	}
}

void printMatrixByColumns(int m[][MAX_SIZE], int rows, int cols)
{
	for (int currentCol = 0; currentCol < cols; ++currentCol)
	{
		for (int currentRow = 0; currentRow < rows; ++currentRow)
		{
			std::cout << m[currentRow][currentCol] << ' ';
		}

		std::cout << std::endl;
	}
}

void printMatrixByRows(int m[][MAX_SIZE], int rows, int cols)
{
	for (int currentRow = 0; currentRow < rows; ++currentRow)
	{
		printRow(m[currentRow], cols);
		std::cout << std::endl;
	}
}

// очакваме квадратна матрица
bool isSymetric(int matrix[][MAX_SIZE], int n)
{
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < row; ++col)
		{
			if (matrix[row][col] != matrix[col][row])
			{
				return false;
			}
		}
	}

	return true;
}

// разчитаме, че start е валидна позиция
int findIndexOfMin(int array[], int n, int start)
{
	int minIndex = start;
	for (int i = start + 1; i < n; ++i)
	{
		if (array[i] < array[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

void sort(int array[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int minIndex = findIndexOfMin(array, n, i);

		if(minIndex != i)
			std::swap(array[i], array[minIndex]);
	}
}

void sortRows(int matrix[][MAX_SIZE], int rows, int cols)
{
	for (int currentRow = 0; currentRow < rows; ++currentRow)
	{
		sort(matrix[currentRow], cols);
	}
}

// binary search
bool isElementIn(int array, int n, int element)
{
	// TODO
	return false;
}

int main()
{
	int matrix[MAX_SIZE][MAX_SIZE];

	readMatrix(matrix, 3, 3);
	sortRows(matrix, 3, 3);
	printMatrixByRows(matrix, 3, 3);

	return 0;
}