#include <iostream>

const int MAX_ROWS_COLS = 10;

bool isTraversable(char** matrix, int x, int y) {
	if (x < 0 || x >= MAX_ROWS_COLS || y < 0 || y >= MAX_ROWS_COLS)
		return false;
	
	return matrix[x][y] == '1';
}


//We can traverse diagonally as well
void visit_island(char** matrix, int x, int y) {
	if (!isTraversable(matrix, x, y))
		return;

	matrix[x][y] = 'x';

	visit_island(matrix, x - 1, y - 1);
	visit_island(matrix, x - 1, y);
	visit_island(matrix, x - 1, y + 1);
	visit_island(matrix, x, y - 1);
	visit_island(matrix, x, y + 1);
	visit_island(matrix, x + 1, y - 1);
	visit_island(matrix, x + 1, y);
	visit_island(matrix, x + 1, y + 1);
}

int islands_count(char** matrix) {
	int count = 0;

	for(int i = 0; i < MAX_ROWS_COLS; ++i)
		for (int j = 0; j < MAX_ROWS_COLS; ++j)
			if (isTraversable(matrix, i, j)) {
				visit_island(matrix, i, j);
				count++;
			}
	return count;
}

void input(char** matrix) {
	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		for (int j = 0; j < MAX_ROWS_COLS; ++j)
			std::cin >> matrix[i][j];
}

int main() {

	char** matrix = new char* [MAX_ROWS_COLS];

	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		matrix[i] = new char[MAX_ROWS_COLS];

	input(matrix);

	std::cout << "This map has " << islands_count(matrix) << " islands\n";

	
	for (int i = 0; i < MAX_ROWS_COLS; ++i)
		delete[] matrix[i];

	delete[] matrix;

	return 0;
}