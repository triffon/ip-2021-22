/*
    Problem: Write a program that reads a number N from STDIN
             (N between 1 and 100) and writes on STDOUT all
             possible ways to express N as a sum of two prime
             numbers (e.g. 20 -> 1 + 19, 3 + 17 & 7 + 13).
*/
#include<iostream>

using namespace std;

const int ONE = 1;
const int A_HUNDRED = 100;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

bool isPrime(int number) {
    for (int test = 2; test < number; ++test) {
        if (number % test == 0) {
            return false;
        }
    }

    return number > 0;
}

int main() {
    int counter = 0;
    int n = readVariable("N", ONE, A_HUNDRED);

    for(int i = 1; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n-i)) {
            counter++;
            cout << i << " + " << n-i << endl;
        }
    }

    cout << "Total: " << counter << endl;

    return 0;
}