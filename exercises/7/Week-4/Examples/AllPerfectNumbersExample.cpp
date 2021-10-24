/*
    Problem: Write a program that reads a number N from
             STDIN (N between 1 and 1000000) and writes
             on STDOUT N with all "perfect" numbers
             between 1 and N incl. A number is considered
             perfect if it is equal to the sum of its
             divisors - e.g. 6 = 1 + 2 + 3.
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

int sumOfAllDivisors(int n) {
    int result = 1;

    for(int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            result += i;
        }
    }

    return result;
}

int main() {
    int n = readVariable("N", ONE, ONE_MILION);

    for(int i = 1; i < n; ++i) {
        if (sumOfAllDivisors(i) == i) {
            cout << "The number " << i << " is \"perfect\"." << endl;
        }
    }

    return 0;
}
