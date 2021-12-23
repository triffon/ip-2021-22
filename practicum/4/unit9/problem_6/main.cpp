#include <iostream>

/*
		Създайте функция `char* findChar(char matrix[][128], int rows, int cols, char c)`,
		която връща указател към първия ред на матрицата, който съдържа символът `c`,
		или `nullptr`, ако този символ не съществува в матрицата. 
		След извикването на тази функция, без да се обхожда матрицата отново, да се изведе
		на кой и ред и коя колона се намира символът
		Подсказка: Използвайте указателя, за да пресметнете разстоянието от началото на матрицата.
*/

const int MAX_SIZE = 128;

void readMatrix(char m[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> m[i][j];
		}
	}
}

char* findChar(char matrix[][MAX_SIZE], int rows, int cols, char c) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == c) {
				return &matrix[i][j];
			}
		}
	}
	return nullptr;
}

int main() {
	char matrix[MAX_SIZE][MAX_SIZE];
	int rows, cols;
	std::cin >> rows >> cols;
	readMatrix(matrix, rows, cols);
	char c;
	std::cin >> c;
	char *foundChar = findChar(matrix, rows, cols, c);
	if (foundChar) {
		const int offset = (int)foundChar - (int)matrix; // Разстояние (в байтове) от адреса на намерения символ до началото на матрицата.
		std::cout << "The matrix contains the character at row: " << offset/MAX_SIZE << " col: " << offset%MAX_SIZE;
	} else {
		std::cout << "The matrix did not contain the character";
	}


	return 0;
}