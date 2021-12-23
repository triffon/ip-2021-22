#include <iostream>

#define MAX_SIZE 64

void printMatrix(int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
}