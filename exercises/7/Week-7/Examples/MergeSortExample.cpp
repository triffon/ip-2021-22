/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 100)
             and then subsequently reads N numbers from STDIN. At the end of the
             program write on STDOUT the numbers in sorted order using merge sort.
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

void printArray(string name, int n, int elements[]) {
   for(int i = 0; i < n; ++i) {
       cout << name << "[" << i << "] = " << elements[i] << endl;
   }
}

void copy(int *source, int *target, int length) {
    for (int i = 0; i < length; ++i) {
        target[i] = source[i];
    }
}

void merge(int *arrayA, int lengthA, int *arrayB, int lengthB, int *buffer) {
    for(int i = 0, j = 0, k = 0; i < lengthA + lengthB; i++) {
        if ((j < lengthA && k == lengthB) || (j < lengthA && k < lengthB && arrayA[j] < arrayB[k])){
            buffer[i] = arrayA[j];
            j = j + 1;
        } else {
            buffer[i] = arrayB[k];
            k = k + 1;
        }
    }    
}

void mergeSort(int *array, int *buffer, int length) {
    if (length < 2) {
        return;
    }

    int *left = array;
    int lengthLeft = length / 2;
    int *right = array + lengthLeft;
    int lengthRight = length - lengthLeft; 

    mergeSort(left, buffer, lengthLeft);
    mergeSort(right, buffer, lengthRight);
    merge(left, lengthLeft, right, lengthRight, buffer);
    copy(buffer, array, length);
}

int main() {
    int elements[100];
    int sortBuffer[100];
    int n = readVariable("N", 5, 100);

    readArray("unsorted", n, elements);
    mergeSort(elements, sortBuffer, n);
    printArray("sorted", n, elements);

    return 0;
}