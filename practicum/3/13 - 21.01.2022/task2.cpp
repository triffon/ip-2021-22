#include <iostream>

int getIslandSize(int matrix[][100], bool visited[][100], int n, int m, int row, int col)
{
  if (row < 0 || row >= n || col < 0 || col >= m)
  {
    return 0;
  }

  if (visited[row][col] || matrix[row][col] == 0)
  {
    return 0;
  }

  visited[row][col] = true;

  return 1 + getIslandSize(matrix, visited, n, m, row - 1, col) 
      + getIslandSize(matrix, visited, n, m, row + 1, col) 
      + getIslandSize(matrix, visited, n, m, row, col - 1)
      + getIslandSize(matrix, visited, n, m, row, col + 1);
}

void clearMatrix(bool matrix[][100], int n, int m)
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      matrix[i][j] = false;
    }
  }
}

int getBiggestIslandSize(int matrix[][100], int n, int m)
{
  int maxSize = 0;
  bool visited[100][100]{};

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      int size = getIslandSize(matrix, visited, n, m, i, j);

      if (size > maxSize)
      {
        maxSize = size;
      }

      clearMatrix(visited, n, m);
    }
  }
  
  return maxSize;
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

  return 0;
}