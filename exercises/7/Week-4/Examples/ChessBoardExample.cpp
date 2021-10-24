/*
    Problem: Write a program that reads the coordinates of two chess
             board squares (X and Y) from STDIN and writes on STDOUT
             whether a pawn, a rook or a bishop can go from X to Y.
*/

#include<iostream>

using namespace std;

const char A = 'A';
const char H = 'H';

const int ONE = 1;
const int EIGHT = 1000000;

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

bool isValidPawnMove(char x_1, int x_2, char y_1, int y_2) {
    return (y_2 - x_2 == 1) && x_1 == y_1;
}

bool isValidRookMove(char x_1, int x_2, char y_1, int y_2) {
    return (y_1 == x_1) || (x_2 == y_2);
}

bool isValidBishopMove(char x_1, int x_2, char y_1, int y_2) {
    return (x_1 - y_1) == (x_2 - y_2);
}

int main() {
    char x_1 = readVariable("Column X", A, H);
    int x_2 = readVariable("Row X", ONE, EIGHT);

    char y_1 = readVariable("Column Y", A, H);
    int y_2 = readVariable("Row Y", ONE, EIGHT);

    if (isValidPawnMove(x_1, x_2, y_1, y_2)) {
        cout << "A pawn can move from " << x_1 << x_2 << " to " << y_1 << y_2 << endl;
    }

    if (isValidRookMove(x_1, x_2, y_1, y_2)) {
        cout << "A rook can move from " << x_1 << x_2 << " to " << y_1 << y_2 << endl;
    }

    if (isValidBishopMove(x_1, x_2, y_1, y_2)) {
        cout << "A bishop can move from " << x_1 << x_2 << " to " << y_1 << y_2 << endl;
    }

    return 0;
}
