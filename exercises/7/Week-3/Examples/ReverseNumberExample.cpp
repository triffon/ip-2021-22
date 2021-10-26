/*
    Problem: Write a program that reads a number N from STDIN
             (N between 1 and 1000000) and writes on STDOUT N
             with all digits reversed (e.g. 12345 -> 54321).
*/

#include<iomanip>
#include<iostream>

using namespace std;

const int ONE = 1;
const int A_MILION = 1000000;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int getReversed(int n) {
    int reversed = 0;

    do {
        reversed = reversed * 10 + (n % 10);
        n = n / 10;
    } while (n > 0);

    return reversed;
}

int getNumberOfDigits(int n) {
    int digits = 1;

    while(n > 9) {
        digits = digits + 1;
        n = n / 10;
    }

    return digits;    
}

int main() {
    int n = readVariable("N", ONE, A_MILION);
    int reversedN = getReversed(n);
    int numberOfDigits = getNumberOfDigits(n);

    cout << setfill('0') << setw(numberOfDigits) << reversedN << endl;

    return 0;
}