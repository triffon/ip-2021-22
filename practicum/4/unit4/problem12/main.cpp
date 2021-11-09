#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter number: ";
    cin >> number;
    bool hasIdentical = false;
    while (number > 0) {
        int wholePart = number / 10;
        int numberToCheck = number % 10;
        while (wholePart > 0) {
            if (numberToCheck == wholePart % 10) {
                hasIdentical = true;
            }
            wholePart /= 10;
        }
        number /= 10;
    }
    hasIdentical ? cout << "Yes" : cout << "No";

    return 0;
}