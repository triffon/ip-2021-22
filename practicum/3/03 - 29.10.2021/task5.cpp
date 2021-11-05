#include <iostream>

using namespace std;

int main() {
    int n;
    int product = 1;

    do {
        cin >> n;
        if (n % 3 == 1) {
            product *= n;
        }
    } while (n >= 0);

    cout << product << endl;

    return 0;
}
