/*  
	Създайте функция, която проверява дали в квадратна матрица елементите на главния диагонал са уникални.
	Създайте функция, която прави същата проверка, но за вторичния диагонал.
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

bool mainDiagHasUniqueEls(int arr[][MAX_SIZE], int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = i + 1; j < matrixSize; j++) {
			if (arr[i][i] == arr[j][j]) return false;
		}
	}
	return true;
}

bool secondaryDiagHasUniqueEls(int arr[][MAX_SIZE], int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = i + 1; j < matrixSize; j++) {
			if (arr[i][matrixSize - i - 1] == arr[j][matrixSize - j - 1]) return false;
		}
	}
	return true;
}


int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int size;
	std::cin >> size;
	readMatrix(matrix, size, size);

	std::cout << (mainDiagHasUniqueEls(matrix, size) ? "The main diagonal has unique numbers\n" : "The main diagonal does not have unique numbers\n");
	std::cout << (secondaryDiagHasUniqueEls(matrix, size) ? "The secondary diagonal has unique numbers" : "The secondary diagonal does not have unique numbers");
	return 0;
}