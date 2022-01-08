#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 1а
// очакваме квадратна матрица
bool isSymetric(int matrix[][MAX_SIZE], int n)
{
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < row; ++col)
        {
            if (matrix[row][col] != matrix[col][row])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    read(matrix, 4, 4);
    std::cout << "Is symetric: " << std::boolalpha << isSymetric(matrix, 4);

    return 0;
}
