/*
    Problem: Write a program that reads numbers N and X from STDIN
             (N, X between 1 and 20) and writes on STDOUT the sum
             of the series [x - x^3 + x^5 - ... ± x^N].
*/

#include<math.h>
#include<iostream>

using namespace std;

const int ONE = 1;
const int TWENTY = 20;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int calculatePolinom(int n, int x) {
    int sign = 1;
    int result = 0;

    for(int i = 1; i <= n; i+= 2) {
        result += sign * (int)pow(x, i);
        sign = -1 * sign;
    }

    return result;
}

int main() {
    int n = readVariable("N", ONE, TWENTY);
    int x = readVariable("X", ONE, TWENTY);

    cout << "Result: " << calculatePolinom(n, x) << endl;

    return 0;
}