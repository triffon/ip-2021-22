/*  
	Създайте функция, която проверява дали всички цели числа в двумерен масив са различни.
	Числата в двумерния масив могат да са само от 0 до 100. Използвайте това ограничение,
	за да реализирате по-оптимален алгоритъм.
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

bool hasUniqueNumbers(int arr[][MAX_SIZE], int rows, int cols) {
	bool numberSeen[101] = { false }; // numberSeen[i] е true, ако при обхождането, вече сме срещнали числото i.

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (numberSeen[arr[i][j]]) return false;
			numberSeen[arr[i][j]] = true;
		}
	}
	return true;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);

	std::cout << (hasUniqueNumbers(matrix, rows, cols) ? "The matrix has unique numbers\n" : "The matrix does not have unique numbers\n");
	return 0;
}