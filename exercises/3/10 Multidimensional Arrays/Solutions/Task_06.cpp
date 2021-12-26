#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 6
bool isValidPosition(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int sumNeighbours(int matrix[][MAX_SIZE], int n, int m, int i, int j)
{
    int sum = 0;
    for (int di = -1; di <= 1; ++di)
    {
        for (int dj = -1; dj <= 1; ++dj)
        {
            if (isValidPosition(i + di, j + dj, n, m))
            {
                sum += matrix[i + di][j + dj];
            }
        }
    }

    return sum - matrix[i][j];
}

bool hasElemEqualToSumNeighbours(int matrix[][MAX_SIZE], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (sumNeighbours(matrix, n, m, i, j) == matrix[i][j])
                return true;
        }
    }

    return false;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    read(matrix, 4, 5);
    std::cout
        << "Is there an element equal to its neighbours? "
        << std::boolalpha << hasElemEqualToSumNeighbours(matrix, 4, 5) << std::endl;

    return 0;
}
