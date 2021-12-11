/*
    Problem: Write a program that reads a number N from STDIN (1 < N < 11) and
             subsequently reads from STDIN the numbers comprising a NxN matrix A.
             At the end of the program write on STDOUT the position of the first
             non-negative element that is on the main diagonal of A.
*/

#include<iostream>
#include <limits.h>

using namespace std;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

void readArray(string name, int n, int elements[]) {
   for(int i = 0; i < n; ++i) {
       elements[i] = readVariable(name + "[" + to_string(i) + "]", INT_MIN, INT_MAX);
   }
}

void readMatrix(string name, int n, int matrix[][10]) {
    for (int i = 0; i < n; ++i) {
        readArray(name + "[" + to_string(i) + "]", n, matrix[i]);
    }
}

int find(int matrix[10][10], int n) {
    for(int i = 0; i < n; ++i) {
        if (matrix[i][i] >= 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    int matrix[10][10];
    int n = readVariable("N", 2, 10);

    readMatrix("A", n, matrix);

    cout << "Position: " << find(matrix, n) << endl;

    return 0;
}