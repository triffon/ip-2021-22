/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 50)
             and then subsequently reads two vectors consisting of N numbers each
             from STDIN. At the end of the program write on STDOUT the entrywise
             product of the two vectors.
*/

#include<iostream>
#include<algorithm>
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

void readArray(string name, int elements[], int length) {
   for(int i = 0; i < length; ++i) {
       elements[i] = readVariable(name + "[" + to_string(i) + "]", INT_MIN, INT_MAX);
   }
}

void printArray(string name, int elements[], int length) {
   for(int i = 0; i < length; ++i) {
       cout << name << "[" << i << "] = " << elements[i] << endl;
   }
}

void calculateEntrywiseProduct(int a[], int b[], int c[], int length) {
    for(int i = 0; i < length; ++i) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    int a[50], b[50], c[50];
    int n = readVariable("N", 5, 50);

    readArray("a", a, n);
    readArray("b", b, n);
    calculateEntrywiseProduct(a, b, c, n);
    printArray("c", c, n);

    return 0;
}