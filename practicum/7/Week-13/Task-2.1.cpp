#include<iostream>
const int MAX_ROWS_COLS = 10;

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

bool isTraversable(char** matrix, int x, int y) {
	if (x < 0 || x >= MAX_ROWS_COLS || y < 0 || y >= MAX_ROWS_COLS)
		return false;

	return matrix[x][y] == 'o' || matrix[x][y] == 'S' || matrix[x][y] == 'E';
}

bool print_path(char** matrix, int x, int y, int** coordinates, int& i) {
	if (!isTraversable(matrix, x, y))
		return false;

	if (matrix[x][y] == 'E')
		return true;

	matrix[x][y] = 'x'; //means we visited the element

	bool res = print_path(matrix, x - 1, y, coordinates, i) || //up
		print_path(matrix, x, y + 1, coordinates, i) || //right
		print_path(matrix, x + 1, y, coordinates, i) || //down
		print_path(matrix, x, y - 1, coordinates, i); //left

	if (res) {
		matrix[x][y] = '.';
		coordinates[0][i] = x;
		coordinates[1][i] = y;
		++i;
	}

	return res;
}

void print_path(char** matrix) {
	int** coordinates = new int* [2];
	for (int i = 0; i < 2; ++i)
		coordinates[i] = new int[MAX_ROWS_COLS * MAX_ROWS_COLS];

	int size = 0;
	std::cout << std::boolalpha << print_path(matrix, 1, 0, coordinates, size) << std::endl;

	for (int i = size - 1; i >= 0; --i)
		std::cout << '(' << coordinates[0][i] << ", " << coordinates[1][i] << ')' << std::endl;
	
	std::cout << std::endl;

	print(matrix);

	for (int i = 0; i < 2; ++i)
		delete[] coordinates[i];

	delete[] coordinates;
}

int main() {

	char** matrix = new char* [MAX_ROWS_COLS];

	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		matrix[i] = new char[MAX_ROWS_COLS];

	input(matrix);

	print_path(matrix);

	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		delete[] matrix[i];

	delete[] matrix;

	return 0;
}