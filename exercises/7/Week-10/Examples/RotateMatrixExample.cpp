/*
    Problem: Write a program that reads a number N from STDIN (1 < N < 11)
             and subsequently reads from STDIN the numbers comprising a NxN
             matrix A. At the end of the program write on STDOUT A after
             'rotating' its elements arount the main diagonal of A.
*/

#include<iostream>
#include <limits.h>
#include<algorithm>

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

void printMatrix(string name, int n, int matrix[10][10]) {
    for (int i = 0; i < n; ++i) {
        printArray(name + "[" + to_string(i) + "]", n, matrix[i]);
    }
}

void rotate(int matrix[10][10], int n) {
    int result = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    int matrix[10][10];
    int n = readVariable("N", 2, 10);

    readMatrix("A", n, matrix);
    rotate(matrix, n);
    printMatrix("Ar", n, matrix);

    return 0;
}