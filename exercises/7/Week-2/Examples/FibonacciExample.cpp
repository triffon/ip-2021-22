/*
    Problem: Write a program that reads a number N from STDIN
             (N between 0 and 100) and writes on STDOUT:
	             - the Nth number in the Fibonacci sequence (using a for-loop)
	             - the Nth number in the Fibonacci sequence (using a reqursive function)*
*/

#include<chrono>
#include<iostream>

using namespace std;
using namespace std::chrono;

const int ZERO = 0;
const int A_HUNDRED = 100;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

long fibonacciIteration(int n) {
    long fibA = 0, fibB = 1;

    for(int i = 0; i < n; i++) {
        fibB = fibB + fibA;
        fibA = fibB - fibA;
    }

    return fibA;
}

long fibonacciRecurssion(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacciRecurssion(n - 1) + fibonacciRecurssion(n - 2);
}

long fibonacciLinearRecurssion(long a, long b, int c, int d) {
    return (c == d) ? a : fibonacciLinearRecurssion(b, a + b, c + 1, d);
}

int main() {
    long start, end, result;
    long n = readVariable("N", ZERO, A_HUNDRED);

    start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    result = fibonacciIteration(n);
    end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    cout << n << "th number in the Fibonacci sequence is (iteration): " << result << " (took " << end - start << "ns)" << endl;

    start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    result = fibonacciLinearRecurssion(0, 1, 0, n);
    end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    cout << n << "th number in the Fibonacci sequence is (linear recursiion): " << result << " (took " << end - start << "ns)" << endl;

    start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    result = fibonacciRecurssion(n);
    end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    cout << n << "th number in the Fibonacci sequence is (recursion): " << result << " (took " << end - start << "ns)" << endl;
}