#include <iostream>

bool outOfBounds(int x, int y, int n, int m) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

void findPath(char** lab, int n, int m, int x, int y, int finalX, int finalY, char* path, int pathIndex)
{
    if (outOfBounds(x, y, n, m) || lab[x][y] == 'X') {
        return;
    }
    if (x == finalX && y == finalY) {
        path[pathIndex] = '\0';
        std::cout << path;
        return;
    }

    lab[x][y] = 'X';

    x = x + 1;
    path[pathIndex++] = 'D';
    findPath(lab, n, m, x, y, finalX, finalY, path, pathIndex);
    pathIndex--;
    x = x - 1;

    y = y + 1;
    path[pathIndex++] = 'R';
    findPath(lab, n, m, x, y, finalX, finalY, path, pathIndex);
    pathIndex--;
    y = y - 1;
    
    x = x - 1;
    path[pathIndex++] = 'U';
    findPath(lab, n, m, x, y, finalX, finalY, path, pathIndex);
    pathIndex--;
    x = x + 1;


    y = y - 1;
    path[pathIndex++] = 'L';
    findPath(lab, n, m, x, y, finalX, finalY, path, pathIndex);
    pathIndex--;
    y = y + 1;

    lab[x][y] = '*';
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    char** lab = new char* [n];
    for (int i = 0; i < n; i++)
    {
        lab[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> lab[i][j];
        }
    }

    char* path = new char[n * m];
    findPath(lab, n, m, 0, 0, n - 1, m - 1, path, 0);

    delete[] path;
    for (int i = 0; i < n; i++)
    {
        delete[] lab[i];
    }
    delete[] lab;

    return 0;
}