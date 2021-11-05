#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int index = 1;
    int curr = 2;

    while (index < n) {
        curr++;
        bool prime = true;

        for (int i = 2; i * i <= curr; i++) {
            if (curr % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            index++;
        }
    }

    cout << curr << endl;

    return 0;
}
