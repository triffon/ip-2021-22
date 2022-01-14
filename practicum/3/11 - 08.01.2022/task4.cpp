#include <iostream>

void deleteRowAndCol(int**& mat, int& n, int& m, int row, int col) {
	int** newMat = new int* [n - 1];
	for (int i = 0; i < n - 1; i++) {
		newMat[i] = new int[m - 1];
	}

	for (int i = 0; i < n; i++) {
		if (i == row)
			continue;

		for (int j = 0; j < m; j++) {
			if (j == col)
				continue;

			newMat[(i > row) ? i - 1 : i][(j > col) ? j - 1 : j] = mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;

	mat = newMat;
	n--;
	m--;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> mat[i][j];
		}
	}

	int min = mat[0][0], minRow = 0, minCol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] < min) {
				min = mat[i][j];
				minRow = i;
				minCol = j;
			}
		}
	}

	deleteRowAndCol(mat, n, m, minRow, minCol);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	
	return 0;
}