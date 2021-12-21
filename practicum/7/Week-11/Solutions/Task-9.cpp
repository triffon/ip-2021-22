#include <iostream>

bool even(int n) {
	return !(n % 2);
}

int matrixSum(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += even(matrix[i][j]) * matrix[i][j];  //eval the predicate even and if its true then will be added to the sum
		}
	}
	return sum;
}

int main()
{
	//Test it.
	return 0;
}