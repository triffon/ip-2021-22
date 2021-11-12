#include <iostream>

using namespace std;

int main() {
    int a, b;
    do {
        cin >> a >> b;
    } while (a > b);

    for (int i = a; i <= b; i++) {
        if (i % 7 == 0 && i % 3 != 0) {
            cout << i << endl;
        }
    }

    return 0;
}
