#include "io.h"

#include <iostream>

void read(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
}

void print(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << ' ';
    }
}

// функции за прочитане и извеждане на матрица...
void read(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int currentRow = 0; currentRow < rows; ++currentRow)
    {
        read(matrix[currentRow], cols);
    }
}

void printByColumns(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int currentCol = 0; currentCol < cols; ++currentCol)
    {
        for (int currentRow = 0; currentRow < rows; ++currentRow)
        {
            std::cout << matrix[currentRow][currentCol] << ' ';
        }

        std::cout << std::endl;
    }
}

void printByRows(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int currentRow = 0; currentRow < rows; ++currentRow)
    {
        print(matrix[currentRow], cols);
        std::cout << std::endl;
    }
}