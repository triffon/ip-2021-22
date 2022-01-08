#include <iostream>

int maxRow(int** matrix, int n) {
	int max = INT_MIN;
	int sum;
	int maxRowIndex;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += matrix[i][j];
		}
		if (sum > max) {
			maxRowIndex = i;
			max = sum;
		}
	}
}

int maxCol(int** matrix, int n) {
	int max = INT_MIN;
	int sum;
	int maxColIndex;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += matrix[j][i];
		}
		if (sum > max) {
			maxColIndex = i;
			max = sum;
		}
	}
}


int main()
{
	//Test it.
	//Getting the row by given index is easy.
	//Getting the column by given index is:

	//Use the above functions to get the indeces.

	/*for (int i = 0; i < n; i++)
	{
		matrix[i][givenIndex];
	}*/
	return 0;
}