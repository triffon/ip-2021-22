#include <iostream>

bool canAttackOther(char** mat, int n, int m, int row, int col) {
	for (int i = 0; i < n; i++) {
		if (i != row && mat[i][col] == 'O')
			return true;
	}

	for (int i = 0; i < m; i++) {
		if (i != col && mat[row][i] == 'O')
			return true;
	}

	for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
		if (mat[row - i][col - i] == 'O')
			return true;
	}

	for (int i = 1; row + i < n && col + i < m; i++) {
		if (mat[row + i][col + i] == 'O')
			return true;
	}

	for (int i = 1; row - i >= 0 && col + i < m; i++) {
		if (mat[row - i][col + i] == 'O')
			return true;
	}

	for (int i = 1; row + i < n && col - i >= 0; i++) {
		if (mat[row + i][col - i] == 'O')
			return true;
	}

	return false;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	char** mat = new char* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new char[m];
		for (int j = 0; j < m; j++) {
			std::cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'O') {
				if (canAttackOther(mat, n, m, i, j)) {
					std::cout << "Attack" << std::endl;
					return 0;
				}
			}
		}
	}
	std::cout << "Can't attack" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 'O' && !canAttackOther(mat, n, m, i, j)) {
				std::cout << i << " " << j << std::endl;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	return 0;
}