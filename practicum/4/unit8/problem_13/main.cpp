/*  
	Създайте програма, която обръща огледално матрица.
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

void flip(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols / 2; j++) {
			int x = arr[i][j];
			arr[i][j] = arr[i][cols - j - 1];
			arr[i][cols - j - 1] = x;
		}
	}
}


int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	flip(matrix, rows, cols);

	std::cout << "\nAfter flipping:\n";
	printMatrix(matrix, rows, cols);
	return 0;
}