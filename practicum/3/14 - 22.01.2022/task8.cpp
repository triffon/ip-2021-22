#include <iostream>

int min(int a, int b)
{
  if (a == -1)
  {
    return b;
  }

  if (b == -1)
  {
    return a;
  }

  return a > b ? b : a;
}

int min(int a, int b, int c, int d)
{
  return min(min(min(a, b), c), d);
}

int shortestPathBetween(int matrix[][100], bool visited[][100], int n, int m, int rowCurr, int colCurr, int rowEnd, int colEnd)
{
  if (rowCurr < 0 || rowCurr >= n || colCurr < 0 || colCurr >= m)
  {
    return -1;
  }

  if (rowEnd == rowCurr && colEnd == colCurr)
  {
    return 0;
  }

  if (visited[rowCurr][colCurr] || matrix[rowCurr][colCurr] == 0)
  {
    return -1;
  }

  visited[rowCurr][colCurr] = true;

  int pathUpwards = shortestPathBetween(matrix, visited, n, m, rowCurr - 1, colCurr, rowEnd, colEnd);
  int pathDownwards = shortestPathBetween(matrix, visited, n, m, rowCurr + 1, colCurr, rowEnd, colEnd);
  int pathLeft = shortestPathBetween(matrix, visited, n, m, rowCurr, colCurr - 1, rowEnd, colEnd);
  int pathRight = shortestPathBetween(matrix, visited, n, m, rowCurr, colCurr + 1, rowEnd, colEnd);

  visited[rowCurr][colCurr] = false;

  return 1 + min(pathDownwards, pathUpwards, pathLeft, pathRight);
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  int matrix[100][100];
  bool visited[100][100]{};

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
  
  int rowStart, colStart, rowEnd, colEnd;
  std::cin >> rowStart >> colStart >> rowEnd >> colEnd;


  std::cout << shortestPathBetween(matrix, visited, n, m, rowStart, colStart, rowEnd, colEnd) << std::endl;

  return 0;
}