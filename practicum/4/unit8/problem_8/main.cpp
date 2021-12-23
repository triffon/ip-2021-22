/*  
	Създайте функция, която връща дали дадена квадратна матрица е симетрична спрямо главния си диагонал.
	Също създайте функция, която прави същото, но спрямо вторичния диагонал.
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

bool symmetricalMainDiag(int arr[][MAX_SIZE], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i][j] != arr[j][i]) return false;
		}
	}
	return true;
}

bool symmetricalSecondaryDiag(int arr[][MAX_SIZE], int n) {
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= n - i - 2; j++) {
			if (arr[i][j] != arr[n-j-1][n-i-1]) return false;
		}
	}
	return true;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int n;
	std::cin >> n;
	readMatrix(matrix, n, n);
	std::cout << (symmetricalMainDiag(matrix, n) ? "It is symmetrical against its main diagonal\n" : "It is not symmetrical against its main diagonal\n");
	std::cout << (symmetricalSecondaryDiag(matrix, n) ? "It is symmetrical against its secondary diagonal\n" : "It is not symmetrical against its secondary diagonal\n");
	return 0;
}