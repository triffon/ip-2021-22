/*  
	Създайте програма, която по даден двумерен масив, разменя редове, съдържащи най-големия и най-малкия елемент
	от целия двумерен масив.
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

void swapRows(int arr[][MAX_SIZE], int row1Idx, int row2Idx, int cols) {
	for (int i = 0; i < cols; i++) {
		int x = arr[row1Idx][i];
		arr[row1Idx][i] = arr[row2Idx][i];
		arr[row2Idx][i] = x;
	}
}

void swapMinMaxRows(int arr[][MAX_SIZE], int rows, int cols) {
	int minElRow = 0;
	int maxElRow = 0;
	int minEl = arr[0][0];
	int maxEl = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < minEl) {
				minEl = arr[i][j];
				minElRow = i;
			}
			if (arr[i][j] > maxEl) {
				maxEl = arr[i][j];
				maxElRow = i;
			}
		}
	}
	swapRows(arr, minElRow, maxElRow, cols);
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	swapMinMaxRows(matrix, rows, cols);

	std::cout << "\nAfter swapping:\n";
	printMatrix(matrix, rows, cols);
	return 0;
}