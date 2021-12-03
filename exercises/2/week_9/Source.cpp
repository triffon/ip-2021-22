#include <iostream>

using namespace std;

const unsigned ROWS = 4;
const unsigned COLUMNS = 3;

void increment(int matrix[4][3])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			matrix[i][j] += 2;
		}
	}
}

void print(int matrix[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void transpose(int A[3][3], int B[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			B[i][j] = A[j][i];
		}
	}
}

int main() {

	int arr[] = { 1,2,3,4,5,6,7,8,9 };


	int matrix[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };


	int matrix2[3][3];

	
	print(matrix);
	cout << endl;
	//increment(matrix);
	//print(matrix);

	//transpose(matrix, matrix2);

	//print(matrix2);
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < COLUMNS; j++)
	//	{
	//		if (i == j)
	//		{
	//			cout << matrix[i][j] << " ";
	//		}
	//	}
	//	cout << endl;
	//}

	int first = 0, last= 2;
	while (first <= 2 && last >= 0)
	{
		cout << matrix[first][last] << " ";
		first++;
		last--;
	}


	return 0;
}