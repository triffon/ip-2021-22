/*
    Problem: Write a program that reads two numbers A and B
             from STDIN (A,B between 1 and 1000000) and
             writes on STDOUT the greatest common divisor
             of A and B calculated using the Euclid's algorithm.
*/

#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

const int ONE = 1;
const int ONE_MILION = 1000000;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int calculateGCD(int a, int b) {
    while (a != b)  {
        a = a > b ? a - b : a;
        b = a >= b ? b : b - a;
    }
    
    return a;
}

int main() {
    int a = readVariable("A", ONE, ONE_MILION);
    int b = readVariable("B", ONE, ONE_MILION);

    cout << "GCD of " << a << " and " << b << " is " << calculateGCD(a, b) << endl; 

    return 0;
}