/*
    Problem: Number A is called 'adjacent' if every two consecutive digits of A are
             different. Write a program that reads two numbers A and B from STDIN
             and writes on STDOUT the result of the substraction of the biggest
             and the smallest 'adjacent' numbers in the interval [A; B] (if no such
             numbers exist - an error message shall be printed).
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

bool isAdjacent(int n) {
    for(; n > 9; n /= 10) {
        if(n % 10 == (n / 10) % 10) {
            return false;
        }
    }
    
    return true;
}

int findMinAdjacent(int a, int b) {
    for (int i = a; i <= b; ++i) {
        if(isAdjacent(i)) {
            return i;
        }
    }

    return -1;
}

int findMaxAdjacent(int a, int b) {
    for (int i = b; i >= a; --i) {
        if(isAdjacent(i)) {
            return i;
        }
    }

    return -1;
}

int main() {
    int a = readVariable("A", 0, INT_MAX);
    int b = readVariable("B", a, INT_MAX);

    int min = findMinAdjacent(a, b);
    int max = findMaxAdjacent(a, b);

    if (min == -1 || max == -1) {
        cout << "No 'adjacent' numbers exist in the interval [" << a << ", " << b << "]" << endl;
    } else {
        cout << max - min << endl;
    }

    return 0;
}