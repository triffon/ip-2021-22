#include <iostream>

using namespace std;

int main()
{
    long long binaryNum;
    int decimalNum = 0;
    do
    {
        cout << "Enter a whole non-negative binary number: ";
        cin >> binaryNum;
    }
    while (binaryNum < 0);

    short value = 1;
    while (binaryNum > 0)
    {
        short digit = binaryNum % 10;
        if (digit > 1) {
            cout << "Not a binary number!" << endl;
            return 1;
        }

        decimalNum += digit * value;
        value <<= 1;
        binaryNum /= 10;
    }

    cout << decimalNum;

    return 0;
}
