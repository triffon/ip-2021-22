/*
    Problem: Write a program that reads two numbers N & K from STDIN
             (N between 5 and 50, K between 4 and N) and then subsequently
             reads two sequences - first consisting of N numbers, second
             consisting of K numbers from STDIN. At the end of the program
             write on STDOUT the number of times that the second sequence
             appears in the first one.
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

bool areEqual(int first[], int second[], int length) {
    for(int i = 0; i < length; ++i) {
        if(first[i] != second[i]) {
            return false;
        }
    }

    return true;
}

int contains(int first[], int firstLength, int second[], int secondLength) {
    int result = 0;

    for(int i = 0; i < (firstLength - secondLength) + 1; ++i) {
        result += areEqual(first + i, second, secondLength) ? 1 : 0;
    }

    return result;
}

int main() {
    int first[50], second[50];
    int n = readVariable("N", 5, 50);
    int k = readVariable("K", 4, n);

    readArray("first", first, n);
    readArray("second", second, k);

    cout << "Second sequence is contained " << contains(first, n, second, k) << " times in the first sequence" << endl;

    return 0;
}