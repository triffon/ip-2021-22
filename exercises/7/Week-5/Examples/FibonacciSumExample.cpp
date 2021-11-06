/*
    Problem: Write a program that reads a number N from STDIN (N between 1 and 50)
             and writes on STDOUT the sum of all Fibonacci numbers beteen 0 and N.
*/


#include<iostream>

using namespace std;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

void populateFibonacciSequence(int n, int fibonacciSequence[]) {
    for(int i = 0; i <= n; ++i) {
        if(i < 2) {
            fibonacciSequence[i] = i;
        } else {
            fibonacciSequence[i] = fibonacciSequence[i - 2] + fibonacciSequence[i - 1];
        }
    }
}

int calculateSum(int n, int elements[]) {
    int sum = 0;

    for(int i = 0; i <= n; ++i) {
        sum += elements[i];
    }

    return sum;
}

int main() {
    int fibonacciSequence[51];
    int n = readVariable("N", 1, 50);

    populateFibonacciSequence(n, fibonacciSequence);

    cout << "Sum is: " << calculateSum(n, fibonacciSequence) << endl;

    return 0;
}