/*  
	Създайте функция, която връща дали двумерен масив от цели числа съдържа цялото число Х.
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

bool contains(int arr[][MAX_SIZE], int rows, int cols, int x) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] == x) return true;
		}
	}
	return false;
}


int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	int x;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	std::cin >> x;
	std::cout << std::boolalpha << contains(matrix, rows, cols, x);
	return 0;
}