/* Създайте функция, която връща сумата на положителните елементи в главния диагонал на дадена квадратна матрица. */
#include <iostream>
#define MAX_SIZE 64

void readMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> arr[i][j];
		}
	}
}

int mainDiagonalPositiveSum(int arr[][MAX_SIZE], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i][i];
	}
	return sum;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int n;;
	std::cin >> n;
	readMatrix(matrix, n, n);
	std::cout << mainDiagonalPositiveSum(matrix, n);

	return 0;
}