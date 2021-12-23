/*  
	Създайте функция, която връща произведението на положителните елементи на една матрица, сумата на чиито индекси е четна.
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

int evenIndexSumProduct(int arr[][MAX_SIZE], int rows, int cols) {
	int product = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = (i % 2 == 0 ? 0 : 1); j < cols; j += 2) {
			if (arr[i][j] > 0) {
				product *= arr[i][j];
			}
		}
	}
	return product;
}


int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	std::cout << evenIndexSumProduct(matrix, rows, cols);
	return 0;
}