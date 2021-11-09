#include <iostream>

using namespace std;

int main()
{
    int decimalNum;
    int octalNum = 0;
    cin >> decimalNum;

    int i = 1;
    while (decimalNum > 0)
    {
        octalNum += (decimalNum % 8) * i;
        decimalNum /= 8;
        i *= 10;
    }

    cout << octalNum << '\n';

    return 0;
}
