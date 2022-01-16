#include <iostream>

bool outOfBounds(int x, int y, int matSize) {
	return x < 0 || y < 0 || x >= matSize || y >= matSize;
}

//finalX && finalY are (n-1, n-1)
bool hasPathFromCurrentCell(bool** matrix, int n, int startX, int startY, char* path) {
	if (outOfBounds(startX, startY,n) || !path) { 
		return false;
	}
	if (matrix[startX][startY] == 0) { 
		return false;
	}

	if (startX == n - 1 && startY == n - 1 && matrix[startX][startY] == 1 && path[0] == '\0') {
		return true;
	}

	if (path[0] == 'W') {
		return hasPathFromCurrentCell(matrix, n, startX, startY - 1, path + 1);
	}
	if (path[0] == 'E') {
		return hasPathFromCurrentCell(matrix, n, startX, startY + 1, path + 1);
	}
	if (path[0] == 'N') {
		return hasPathFromCurrentCell(matrix, n, startX - 1, startY, path + 1);
	}
	if (path[0] == 'S') {
		return hasPathFromCurrentCell(matrix, n, startX + 1, startY, path + 1);
	}
}

bool hasPath(bool** matrix, int n, char* path) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (hasPathFromCurrentCell(matrix, n, i, j, path)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	std::cin >> n;
	bool** matrix = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new bool[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	char* testPath = new char[n * n];
	std::cout << "Enter path: ";
	std::cin >> testPath;

	std::cout << std::boolalpha << hasPath(matrix, n, testPath);

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] testPath;
	return 0;
}