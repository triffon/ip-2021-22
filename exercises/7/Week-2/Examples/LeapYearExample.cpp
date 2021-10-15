/*
    Problem: Write a program that reads a number N from STDIN (N between 0
             and 3 000) and writes on STDOUT whether N is a leap year.
*/

#include<iostream>

using namespace std;

const int ZERO = 0;
const int THREE_THOUSAND = 3000;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int main() {
    int year = readVariable("N", ZERO, THREE_THOUSAND);
    bool isLeap = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);

    if (isLeap) {
        cout << "Year " << year << " is leap." << endl;
    } else {
        cout << "Year " << year << " is not leap." << endl;
    }

    return 0;
}