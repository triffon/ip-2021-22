#include <iostream>

using namespace std;

int main() {
    int n, sum = 0;

    cout << "N: ";
    cin >> n; 

    for (int current = 1; current <= n; current++) {
        sum += current;
    }

    cout << "Result: " << sum;

    return 0;
}
