/*
    Problem: Concatenation of two numbers A and B is the number A∘B that contains
             all the digits of A followed by all the digits of B (e.g. A = 12,
             B = 34, A∘B = 1234). Write a program that reads two numbers N and K
             from STDIN and writes on STDOUT whether numbers A and B exist such
             that N = A∘K∘B.
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

bool endsWith(int n, int k) {
    for(; k > 0 && n > 0; k /= 10, n /= 10) {
        if(k % 10 != n % 10) {
            return false;
        }
    }

    return true;
}

bool isConcatenation(int n, int k) {
    for(; n > 9; n /= 10) {
        if(endsWith(n, k)) {
            return true;
        }
    }

    return false;
}

int main() {
    int n = readVariable("N", 0, INT_MAX);
    int k = readVariable("K", 0, INT_MAX);

    cout << (isConcatenation(n / 10, k) ? "True" : "False") << endl;

    return 0;
}
