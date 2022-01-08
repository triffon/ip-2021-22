/*  
	Създайте програма, която прочита матрица и я извежда транспонирана на конзолата.
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

void printTransposed(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << arr[j][i] << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	printTransposed(matrix, rows, cols);
	return 0;
}