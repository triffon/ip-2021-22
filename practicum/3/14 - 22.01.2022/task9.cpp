#include <iostream>

bool getPathBetween(int matrix[][100], bool visited[][100], int n, int m, int rowCurr, int colCurr, int rowEnd, int colEnd, int pathRow[], int pathCol[], int step)
{
  if (rowCurr < 0 || rowCurr >= n || colCurr < 0 || colCurr >= m)
  {
    return false;
  }

  pathRow[step] = rowCurr;
  pathCol[step] = colCurr;

  if (rowEnd == rowCurr && colEnd == colCurr)
  {
    pathRow[step + 1] = -1;
    pathCol[step + 1] = -1;
    return true;
  }

  if (visited[rowCurr][colCurr] || matrix[rowCurr][colCurr] == 0)
  {
    return false;
  }

  visited[rowCurr][colCurr] = true;

  return getPathBetween(matrix, visited, n, m, rowCurr - 1, colCurr, rowEnd, colEnd, pathRow, pathCol, step + 1)
      || getPathBetween(matrix, visited, n, m, rowCurr + 1, colCurr, rowEnd, colEnd, pathRow, pathCol, step + 1)
      || getPathBetween(matrix, visited, n, m, rowCurr, colCurr - 1, rowEnd, colEnd, pathRow, pathCol, step + 1)
      || getPathBetween(matrix, visited, n, m, rowCurr, colCurr + 1, rowEnd, colEnd, pathRow, pathCol, step + 1);
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  int matrix[100][100];
  bool visited[100][100]{};
  int pathRow[100], pathCol[100];

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
  
  int rowStart, colStart, rowEnd, colEnd;
  std::cin >> rowStart >> colStart >> rowEnd >> colEnd;


  std::cout << getPathBetween(matrix, visited, n, m, rowStart, colStart, rowEnd, colEnd, pathRow, pathCol, 0) << std::endl;

  for (size_t i = 0; pathRow[i] != -1 && pathCol[i] != -1; i++)
  {
    std::cout << "(" << pathRow[i] << ", " << pathCol[i] << ")" << std::endl;
  }
  

  return 0;
}