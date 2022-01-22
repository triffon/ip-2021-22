// remainder добави в условията на задачите и за тази (17 от на Дафи)

#include <iostream>

bool matrixContainsWord(char matrix[][100], int n, int m, char* word, int row, int col)
{
  if (*word == '\0')
  {
    return true;
  }

  if (row < 0 || row >= n || col < 0 || col >= m)
  {
    return false;
  }

  if (*word != matrix[row][col])
  {
    return false;
  }

  return matrixContainsWord(matrix, n, m, word + 1, row - 1, col - 1)
      || matrixContainsWord(matrix, n, m, word + 1, row - 1, col + 1)
      || matrixContainsWord(matrix, n, m, word + 1, row + 1, col - 1)
      || matrixContainsWord(matrix, n, m, word + 1, row + 1, col + 1);
}

bool findWordInMatrix(char matrix[][100], int n, int m, char word[])
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      if (matrix[i][j] == *word && matrixContainsWord(matrix, n, m, word, i, j))
      {
        return true;
      }
    }  
  }
    
  return false;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  char matrix[100][100];

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      std::cin >> matrix[i][j];
    } 
  }
  
  char word[100];
  std::cin >> word;

  std::cout << findWordInMatrix(matrix, n, m, word) << std::endl;

  return 0;
}