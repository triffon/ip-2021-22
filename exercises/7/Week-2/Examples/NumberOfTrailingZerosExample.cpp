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

int main() {
    int result = 0;
    int n = readVariable("N", ZERO, A_MILION);

    for (int i = 0; i <= n; i += 5) {
        for (int j = i; j > 0 && j % 5 == 0; j = j / 5) {
            result++;
        }
    }

    cout << "Number of trailing zeros in " << n << "! is " << result << "." << endl; 

    return 0;
}