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
    int n = readVariable("N", ZERO, A_MILION);
    int m = readVariable("M", ZERO, A_MILION);

    // int o;
    // o = n;
    // n = m;
    // m = o;

    n = n + m;
    m = n - m;
    n = n - m; 

    cout << "N: " << n << endl;
    cout << "M: " << m << endl;

    return 0;
}