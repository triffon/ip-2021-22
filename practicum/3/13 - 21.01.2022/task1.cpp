#include <iostream>

bool hasPath(int matrix[][100], bool visited[][100], int n, int m, int rowCurrent, int colCurrent, int rowEnd, int colEnd)
{
  if (rowCurrent == rowEnd && colCurrent == colEnd)
  {
    return true;
  }

  if (rowCurrent < 0 || rowCurrent >= n || colCurrent < 0 || colCurrent >= m)
  {
    return false;
  }

  if (visited[rowCurrent][colCurrent] || matrix[rowCurrent][colCurrent] == 0)
  {
    return false;
  }

  visited[rowCurrent][colCurrent] = true;

  return hasPath(matrix, visited, n, m, rowCurrent - 1, colCurrent, rowEnd, colEnd) || 
    hasPath(matrix, visited, n, m, rowCurrent + 1, colCurrent, rowEnd, colEnd) || 
    hasPath(matrix, visited, n, m, rowCurrent, colCurrent - 1, rowEnd, colEnd) ||
    hasPath(matrix, visited, n, m, rowCurrent, colCurrent + 1, rowEnd, colEnd);
}

int main()
{
  int matrix[100][100];
  bool visited[100][100] {};
  int n, m;

  std::cin >> n >> m;

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      std::cin >> matrix[i][j];
    }
  }

  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  
  std::cout << hasPath(matrix, visited, n, m, x1, y1, x2, y2) << std::endl;
  
  return 0;
}