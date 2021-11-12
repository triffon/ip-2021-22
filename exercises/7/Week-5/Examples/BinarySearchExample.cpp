/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 100)
             and then subsequently reads N numbers from STDIN. At the end of the
             program write on STDOUT whether the numbers include 5, 10 or 50 by
             applying Binary Search.
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

bool binarySearch(int element, int n, int elements[]) {
    int middle;
    int end = n;
    int start = 0;

    while(end - start > 0) {
        middle = (start + end) / 2;

        if(elements[middle] == element) {
            return true;
        }

        end = elements[middle] > element ? middle : end;
        start = elements[middle] > element ? start : middle + 1;
    }

    return false;
}

int main() {
    int elements[100];
    int n = readVariable("N", 5, 100);

    readArray("element", n, elements);
    bubbleSort(n, elements);

    cout << "Found 5: " << binarySearch(5, n, elements) << endl;
    cout << "Found 10: " << binarySearch(10, n, elements) << endl;
    cout << "Found 50: " << binarySearch(50, n, elements) << endl;

    return 0;
}