#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;

    bool isSmallLetter = (c >= 'a') && (c <= 'z');
    cout << isSmallLetter << endl;

    return 0;
}