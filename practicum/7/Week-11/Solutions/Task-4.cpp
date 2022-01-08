#include <iostream>
int** allocate(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];

	return matrix;
}

void deallocate(int** matrix, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

void input(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; ++j)
			std::cin >> matrix[i][j];
}

int* getElementsArr(int** matrix, int rows, int cols) {
	int size = rows * cols;
	int* arr = new int[size];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			arr[--size] = matrix[i][j];

	return arr;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int* arr, int size) {
	int i, j, min;

	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[min])
				min = j;

		swap(arr[min], arr[i]);
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	int** matrix = allocate(n, m);
	input(matrix, n, m);

	int* arr = getElementsArr(matrix, n, m);
	int size = m * n;
	
	sort(arr, size);
	print(arr, size);

	delete[] arr;
	deallocate(matrix, n);
	return 0;
}