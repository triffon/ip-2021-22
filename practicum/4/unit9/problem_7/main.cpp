#include <iostream>

/*
		Създайте функция, която, по даден двумерен масив от цели числа връща указател към първия ред, 
		който съдържа 3 числа, формиращи аритметична прогресия или `nullptr`, ако такъв ред не съществува.
		Извикайте създадената функция и изведете индекса на този ред, без да обхождате матрицата отново.
*/

const int MAX_SIZE = 64;

void readMatrix(int m[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> m[i][j];
		}
	}
}

int isArithmeticProgression(int a, int b, int c) {
	return (c - b) == (b - a);
}

int *firstRowWithArithmeticProg(int m[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols-2; j++) {
			if (isArithmeticProgression(m[i][j], m[i][j+1], m[i][j+2])) {
				return m[i];
			}
		}
	}
	return nullptr;
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);

	int *rowPtr = firstRowWithArithmeticProg(matrix, rows, cols);
	if (rowPtr) {
		const int rowIdx = ((int)rowPtr - (int)matrix) / MAX_SIZE / sizeof(int); // размерът на int е 4 байта :)
		std::cout << "The first row with an arithmetic progression is " << rowIdx;
	} else {
		std::cout << "There isn't a row with an arithmetic progression";
	}

	return 0;
}