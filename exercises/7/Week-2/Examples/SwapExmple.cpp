/*
    Problem: Write a program that reads two numbers N & M from STDIN
             (N & M between 0 and 1 000 000) and swaps their values:
	             - with a third variable O
	             - without a third variable
*/

#include<iostream>

using namespace std;

const int ZERO = 0;
const int A_MILION = 1000000;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int main() {
    int n = readVariable("N", ZERO, A_MILION);
    int m = readVariable("M", ZERO, A_MILION);

    // int o;
    // o = n;
    // n = m;
    // m = o;

    n = n + m;
    m = n - m;
    n = n - m; 

    cout << "N: " << n << endl;
    cout << "M: " << m << endl;

    return 0;
}