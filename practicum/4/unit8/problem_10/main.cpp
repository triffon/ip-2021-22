/*  
	Създайте функция, която разменя първия и най-големия елемент от всеки ред на двумерен масив.
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

void printMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
}

void swapFirstAndBiggestPerRow(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		int maxElIndex = 0;
		for (int j = 1; j < cols; j++) {
			if (arr[i][j] > arr[i][maxElIndex]) {
				maxElIndex = j;
			}
		}
		int x = arr[i][0];
		arr[i][0] = arr[i][maxElIndex];
		arr[i][maxElIndex] = x;
	}
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	swapFirstAndBiggestPerRow(matrix, rows, cols);
	std::cout << "\nAfter swapping:\n";
	printMatrix(matrix, rows, cols);
	return 0;
}