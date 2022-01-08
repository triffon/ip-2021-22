#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 3
void sortMatrixRows(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int currentRow = 0; currentRow < rows; ++currentRow)
    {
        sort(matrix[currentRow], cols);
    }
}

// the rows should be sorted
void printElementsPosition(int matrix[][MAX_SIZE], int n, int m, int element)
{
    for (int row = 0; row < n; ++row)
    {
        // ако има по едно срещане на ред...
        int column = findElementsPosition(matrix[row], m, element);
        if (column != -1)
        {
            std::cout << "Position: (" << row << ", " << column << ")" << std::endl;
        }
    }
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    read(matrix, 4, 5);
    sortMatrixRows(matrix, 4, 5);

    int element = 7;
    printElementsPosition(matrix, 4, 5, element);

    return 0;
}
