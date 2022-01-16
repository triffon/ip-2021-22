#include <iostream>

bool arithmeticalSeq(int* numbers, const int size) {

	int difference = 0;

	difference = numbers[1] - numbers[0];

	for (int i = 0; i < size - 1; i++)
	{
		if (numbers[i] + difference != numbers[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool outOfBounds(int x, int y, int n, int m) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

void findPath(int** lab, bool** visited, int n, int m, int x, int y, int finalX, int finalY, int* path, int pathIndex)
{
	if (outOfBounds(x, y, n, m) || visited[x][y] == 1) {
		return;
	}
	if (x == finalX && y == finalY) {
		path[pathIndex++] = lab[x][y];
		if (arithmeticalSeq(path,pathIndex)) {
			for (int i = 0; i < pathIndex; i++)
			{
				std::cout << path[i] << ' ';
			}
			std::cout << '\n';
		}
		return;
	}

	visited[x][y] = 1;
	path[pathIndex++] = lab[x][y];

	x = x + 1;
	findPath(lab, visited, n, m, x, y, finalX, finalY, path, pathIndex);
	x = x - 1;

	y = y + 1;
	findPath(lab, visited, n, m, x, y, finalX, finalY, path, pathIndex);
	y = y - 1;

	x = x - 1;
	findPath(lab, visited, n, m, x, y, finalX, finalY, path, pathIndex);
	x = x + 1;


	y = y - 1;
	findPath(lab, visited, n, m, x, y, finalX, finalY, path, pathIndex);
	y = y + 1;

	visited[x][y] = 0;
	pathIndex--;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	int** lab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		lab[i] = new int[m];
	}

	bool** visited = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> lab[i][j];
		}
	}


	int* path = new int[n * m];
	findPath(lab, visited, n, m, 0, 1, n - 2, m - 1, path, 0);

	for (int i = 0; i < n; i++)
	{
		delete[] lab[i];
		delete[] visited[i];
	}
	delete[] lab;
	delete[] visited;
	delete[] path;

	return 0;
}