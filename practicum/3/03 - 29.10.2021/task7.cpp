#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int fib_curr = 0, fib_next = 1;

    for (int i = 0; i < n; i++) {
        int tmp = fib_next;

        fib_next += fib_curr;
        fib_curr = tmp;
    }

    cout << fib_curr << endl;

    return 0;
}
