/*
    Problem: Write a program that reads a YEAR (YEAR between 1900 and 9999),
             MONTH (MONTH between 1 and 12) and a DAY (DAY between 1 and 31)
             from STDIN and writes on STDOUT whether they form a valid date.
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

bool isLeapYear(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    return 31;
}

int main() {
    int year = readVariable("YEAR", 1900, 9999);
    int month = readVariable("MONTH", 1, 12);
    int day = readVariable("DAY", 1, 31);

    if (daysInMonth(year, month) < day) {
        cout << "The provided date is not valid." << endl;
    } else {
        cout << "The provided date is valid." << endl;
    }

    return 0;
}