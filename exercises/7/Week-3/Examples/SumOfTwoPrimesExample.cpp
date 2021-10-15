#include<iostream>

using namespace std;

const int ONE = 1;
const int A_HUNDRED = 100;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

bool isPrime(int number) {
    for (int test = 2; test < number; ++test) {
        if (number % test == 0) {
            return false;
        }
    }

    return number > 0;
}

int main() {
    int counter = 0;
    int n = readVariable("N", ONE, A_HUNDRED);

    for(int i = 1; i <= n / 2; i++) {
        if (!isPrime(i)) {
            continue;
        }

        for(int j=n; j + i >= n; j--) {
            if (!isPrime(j)) {
                continue;
            }
            
            if (i + j == n) {
                counter++;
                cout << i << " + " << j << endl;
            }
        }
    }

    cout << "Total: " << counter << endl;

    return 0;
}