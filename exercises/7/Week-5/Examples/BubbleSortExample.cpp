/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 100)
             and then subsequently reads N numbers from STDIN. At the end of the
             program write on STDOUT the numbers in sorted order (smallest number first).
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

void bubbleSort(int n, int elements[]) {
    bool swapped;

    do {
        swapped = false;

        for (int i = 0; i < n - 1; ++i) {
            if(elements[i] > elements[i+1]) {
                swapped = true;
                swap(elements[i], elements[i+1]);
            }
        }
    } while (swapped);
}

int main() {
    int elements[100];
    int n = readVariable("N", 5, 100);

    readArray("element", n, elements);
    bubbleSort(n, elements);
    printArray("element", n, elements);

    return 0;
}