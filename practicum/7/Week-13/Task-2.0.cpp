#include<iostream>
const int MAX_ROWS_COLS = 10;

bool isTraversable(char** matrix, int x, int y) {
	if (x < 0 || x >= MAX_ROWS_COLS || y < 0 || y >= MAX_ROWS_COLS)
		return false;
	
	return matrix[x][y] == 'o' || matrix[x][y] == 'S' || matrix[x][y] == 'E';
}

bool find_path(char** matrix, int x, int y) {
	if (!isTraversable(matrix, x, y))
		return false;

	if (matrix[x][y] == 'E')
		return true;

	matrix[x][y] = 'x'; //means we visited the element

	return find_path(matrix, x - 1, y) ||
		find_path(matrix, x, y + 1) ||
		find_path(matrix, x + 1, y) ||
		find_path(matrix, x, y - 1);
}

void input(char** matrix) {
	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		for (int j = 0; j < MAX_ROWS_COLS; ++j)
			std::cin >> matrix[i][j];
}

void print(char** matrix) {
	for (int i = 0; i < MAX_ROWS_COLS; ++i) {
		for (int j = 0; j < MAX_ROWS_COLS; ++j)
			std::cout << matrix[i][j];
		std::cout << std::endl;
	}
}

int main() {

	char** matrix = new char* [MAX_ROWS_COLS];

	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		matrix[i] = new char[MAX_ROWS_COLS];

	input(matrix);

	std::cout << std::boolalpha << find_path(matrix, 1, 0);

	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		delete[] matrix[i];

	delete[] matrix;

	return 0;
}