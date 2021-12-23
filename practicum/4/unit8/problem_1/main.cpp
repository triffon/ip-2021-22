/* Създайте функция, която извежда минималния елемент от всеки ред на даден двумерен масив. */
#include <iostream>
#define MAX_SIZE 64

void readMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> arr[i][j];
		}
	}
}

void printMinElements(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		int currentMin = arr[i][0];
		for (int j = 1; j < cols; j++) {
			if (arr[i][j] < currentMin) {
				currentMin = arr[i][j];
			}
		}
		std::cout << currentMin << '\n';
	}
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	printMinElements(matrix, rows, cols);

	return 0;
}