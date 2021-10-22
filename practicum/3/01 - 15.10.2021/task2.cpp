#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;

    int digitProduct = 1;
    digitProduct *= number % 10;
    digitProduct *= (number / 10) % 10;
    digitProduct *= (number / 100) % 10;
    digitProduct *= (number / 1000) % 10;
    digitProduct *= (number / 10000) % 10;

    cout << digitProduct << endl;

    return 0;
}