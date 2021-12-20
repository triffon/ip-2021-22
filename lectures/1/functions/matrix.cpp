#include <iostream>
using namespace std;

#include "matrixFunctions.hpp"

// извежда матрицата a с размерност m x n в табличен вид
void printMatrix(int a[][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}