/*
    Problem: Write a program that reads a MONTH (MONTH between 1 and 12) from
             STDIN and writes on STDOUT the season that this month is part of.
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

string toMonthName(int month) {
    switch (month) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "Sepmteber";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        throw invalid_argument(month + " is not a valid month");
    }
}

string toSeason(int month) {
    switch (month) {
    case 3:
    case 4:
    case 5:
        return "Spring";

    case 6:
    case 7:
    case 8:
        return "Summer";

    case 9:
    case 10:
    case 11:
        return "Autumn";

    case 12:
    case 1:
    case 2:
        return "Winter";

    default:
        throw invalid_argument(month + " is not a valid month");
    }
}

int main() {
    int month = readVariable("MONTH", 1, 12);

    cout << "It is " << toSeason(month) << " during " << toMonthName(month) << endl; 

    return 0;
}