#include <iostream>

int** allocate(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];

	return matrix;
}

void deallocate(int** matrix, int rows) {
	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];

	delete[] matrix;
}

void input(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			std::cin >> matrix[i][j];
}

int getRowSum(int** matrix, int rows, int cols){
	int maxSum = INT_MIN;
	int currSum = 0;
	
	for(int i = 0; i < rows; ++i){
		int j = 0;

		for (; j < cols; ++j) {
			if (matrix[i][j] >= 6 || matrix[i][j] % 2) {
				break;
			}

			currSum += matrix[i][j];
		}

		if (j == cols)
			if (maxSum < currSum)
				maxSum = currSum;

		currSum = 0;
	}

	return maxSum;
}

int getColSum(int** matrix, int rows, int cols){
	int maxSum = INT_MIN;
	int currSum = 0;
	
	for (int i = 0; i < cols; ++i) {
		int j = 0;

		for (; j < rows; ++j) {
			if (matrix[j][i] >= 6 || matrix[j][i] % 2) {
				break;
			}

			currSum += matrix[j][i];
		}

		if (j == rows)
			if (maxSum < currSum)
				maxSum = currSum;

		currSum = 0;
	}
	
	return maxSum;
}

int getResult(int rowSum, int colSum) {
	if (rowSum == INT_MIN && colSum == INT_MIN)
		return INT_MIN;

	if (rowSum == INT_MIN)
		return colSum;

	if (colSum == INT_MIN)
		return rowSum;

	return colSum + rowSum;
}

int main(){
	int n, m;
	std::cin >> n >> m;

	int** matrix = allocate(n, m);
	
	input(matrix, n, m);

	int res = getResult(getRowSum(matrix, n, m), getColSum(matrix, n, m));

	if (res == INT_MIN)
		std::cout << "No row and column satisfy the conditions\n";

	else
		std::cout << res;

	deallocate(matrix, n);

	return 0;
}