/*
    Problem: Write a program that reads a number N and a character C from STDIN
             (N between 1 and 20) and writes on STDOUT N lines of C repeated N times.
*/

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

char readVariable(string variableName, char minValue, char maxValue) {
    char variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int main() {
    int n = readVariable("N", ONE, TWENTY);
    char c = readVariable("C", '!', '~');

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << c; 
        }
        cout << endl;
    }

    // A bit of a cheat here... :D
    // for (int i = 0; i < n; i++) {
    //    cout << setfill(c) << setw(n) << "" << endl;
    // }
}