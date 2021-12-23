/* Създайте функция, която извежда броя отрицателни елементи във всеки ред на даден двумерен масив.*/
#include <iostream>
#define MAX_SIZE 64

void readMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> arr[i][j];
		}
	}
}

void printNegativesCount(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		int negativesCount = 0;
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < 0) {
				negativesCount++;
			}
		}
		std::cout << "Row " << i << ": " << negativesCount << " negative numbers.\n";
	}
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	printNegativesCount(matrix, rows, cols);

	return 0;
}