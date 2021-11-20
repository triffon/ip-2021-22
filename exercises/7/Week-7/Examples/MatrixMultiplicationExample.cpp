/*
    Problem: Write a program that reads a number N from STDIN (N between 2 and 10)
             and then reads two NxN matrices from STDIN. At the end of the program
             write on STDOUT the result of the multiplication of the two matrices.
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

void printArray(string name, int n, int elements[]) {
   for(int i = 0; i < n; ++i) {
       cout << name << "[" << i << "] = " << elements[i] << endl;
   }
}

void printMatrix(string name, int n, int matrix[][10]) {
    for (int i = 0; i < n; ++i) {
        printArray(name + "[" + to_string(i) + "]", n, matrix[i]);
    }
}

void multiply(int matrixA[][10], int matrixB[][10], int matrixC[][10], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            matrixC[i][j] = 0;

            for(int k = 0; k < n; k++){
                matrixC[i][j] += matrixA[i][k] + matrixA[k][j];
            }
        }
    }
}

int main() {
    int matrixA[10][10];
    int matrixB[10][10];
    int matrixC[10][10];
    int n = readVariable("N", 2, 10);

    readMatrix("A", n, matrixA);
    readMatrix("B", n, matrixB);

    multiply(matrixA, matrixB, matrixC, n);

    printMatrix("C", n, matrixC);

    return 0;
}