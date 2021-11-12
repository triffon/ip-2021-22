#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cntDivisors = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            cntDivisors++;
        }
    }

    if (cntDivisors != 2 || n == 1) {
        cout << "Not prime" << endl;
    } else {
        cout << "Prime" << endl;
    }

    return 0;
}
