/*  
	Създайте програма, която извежда индекса на този ред от двумерен масив, чиято сума на елементите е най-голяма.
*/
#include <iostream>
#define MAX_SIZE 64

void readMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> arr[i][j];
		}
	}
}

int sum(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int maxRowSumIdx(int arr[][MAX_SIZE], int rows, int cols) {
	int maxSum = sum(arr[0], cols);
	int maxSumIdx = 0;
	for (int i = 1; i < rows; i++) {
		int currentSum = sum(arr[i], cols);
		if (currentSum > maxSum) {
			maxSum = currentSum;
			maxSumIdx = i;
		}
	}
	return maxSumIdx;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);

	std::cout << "Row " << maxRowSumIdx(matrix, rows, cols) << " has the biggest sum\n";
	return 0;
}