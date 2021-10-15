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

int reverseBits(int n, int initial, int step) {
    int reverse = initial;

    while(n > 0) {
        reverse = reverse << step;
        reverse = reverse + (n & initial);
        n = n >> step;
    }

    return reverse;
}

void printBinary(int n) {
    int reversed = reverseBits(n, 1, 1);

    cout << n << " in bianry is: ";

    while (reversed > 1) {
        cout << reversed % 2;
        reversed = reversed / 2;
    }

    cout << endl;
}

void printOctal(int n) {
    int reversed = reverseBits(n, 7, 3);

    cout << n << " in octal is: 0o";

    while (reversed > 7) {
        cout << reversed % 8;
        reversed = reversed / 8;
    }

    cout << endl;
}

void printDecimal(int n) {
    cout << n << " in decimal is: " << n << endl;
}

void printHexademical(int n) {
    int reversed = reverseBits(n, 15, 4);

    cout << n << " in hexadecimal is: 0x";

    while (reversed > 15) {
        if (reversed % 16 < 10) {
            cout << reversed % 16;
        } else {
            cout << char('A' + ((reversed % 16) - 10));
        }

        reversed = reversed / 16;
    }

    cout << endl;
}

int main() {
    int n = readVariable("N", ZERO, A_MILION);

    printBinary(n);
    printOctal(n);
    printDecimal(n);
    printHexademical(n);

    return 0;
}