#include<iostream>

void input(int** matrix, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> matrix[i][j];
}

void print(int** matrix, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[m];

	input(matrix, n, m);
	print(matrix, n, m);
	
	for (int i = 0; i < n; ++i)
		delete[] matrix[i];

	delete[] matrix;

	return 0;
}