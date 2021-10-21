#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char letter = 'A' + n;
    cout << letter << endl;

    // Друг вариант е:
    cout << (char) ('A' + n) << endl;

    return 0;
}