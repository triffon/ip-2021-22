#include <iostream>

/*
	Създайте функция, която намира сумата на елементите под главния диагонал (включително тези на диагонала) на квадратна матрица.
	Също създайте функция, която прави същото с елементите под вторичния диагонал.
*/
const int MAX_SIZE = 64;
int sumBelowMainDiag(int matrix[][MAX_SIZE], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

int sumBelowSecDiag(int matrix[][MAX_SIZE], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= size - i - 1; j--) {
			sum += matrix[i][j];
		}
	}
	return sum;
}
