#include <iostream>
const int N = 4, M = 4;

int** allocate() {
	int** matrix = new int* [N];
	for (int i = 0; i < N; ++i)
		matrix[i] = new int[M];

	return matrix;
}

void deallocate(int** matrix) {
	for (int i = 0; i < N; i++)
		delete[] matrix[i];

	delete[] matrix;
}

void fillMatrix(int** matrix, int* arr) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; ++j)
			matrix[i][j] = arr[i * N + j];
}

void print(int** matrix) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}

int main() {
	int arr[N * M];
	for (int i = 0; i < N * M; i++)
		std::cin >> arr[i];

	int** matrix = allocate();
	fillMatrix(matrix, arr);

	print(matrix);

	deallocate(matrix);
	return 0;
}