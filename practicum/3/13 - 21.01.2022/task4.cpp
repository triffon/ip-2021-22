#include <iostream>

bool canBePlaced(int matrix[8][8], int row, int col)
{
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (matrix[i][j] == 1 &&
          (row == i || col == j || row + col == i + j || row - col == i - j))
      {
        return false;
      }
    } 
  } 
  
  return true;
}

bool canQueensBePlaced(int matrix[8][8], int k, int row, int col)
{
  if (k == 0)
  {
    return true;
  }

  if (row == 7 && col > 7)
  {
    return false;
  }

  if (col > 7)
  {
    row++;
    col %= 8;
  }

  if (canBePlaced(matrix, row, col))
  {
    matrix[row][col] = 1;
    bool withQueen = canQueensBePlaced(matrix, k - 1, row, col + 1);
    matrix[row][col] = 0;
    bool withoutQueen = canQueensBePlaced(matrix, k, row, col + 1);

    return withQueen || withoutQueen;
  }
  
  return canQueensBePlaced(matrix, k, row, col + 1);
}

int main()
{
  int matrix[8][8];

  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      std::cin >> matrix[i][j];
    }
  }

  int k;
  std::cin >> k;

  std::cout << canQueensBePlaced(matrix, k, 0, 0);

}