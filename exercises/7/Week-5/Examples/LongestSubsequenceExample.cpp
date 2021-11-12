/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 100)
             and then subsequently reads N numbers from STDIN. At the end of the
             program write on STDOUT the longest subsequence of the original for
             which it is true that for i < j -> a[i] < a[j].
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

int main() {
    int elements[100];
    int n = readVariable("N", 5, 100);

    readArray("element", n, elements);

    int start = 0;
    int length = 1;

    for(int i = 0; i < n - 1; ++i) {
        int currentStart = i;
        int currentLenght = 1;

        while(i < n - 1 && elements[i] < elements[i+1]) {
            i++;
            currentLenght++;
        }

        if (currentLenght > length) {
            start = currentStart;
            length = currentLenght;
        }
    }

    printArray("subsequence", length, elements + start);

    return 0;
}