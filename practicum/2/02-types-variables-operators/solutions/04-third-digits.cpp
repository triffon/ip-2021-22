#include <iostream>

using namespace std;

/**
 * Въведете 3 произволни петцифрени числа и изведете третите им цифри.
 */
int main()
{
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    int digit1 = ( num1 / 100 ) % 10;
    int digit2 = ( num2 / 100 ) % 10;
    int digit3 = ( num3 / 100 ) % 10;

    cout << digit1 << '\n' << digit2 << '\n' << digit3;

    return 0;
}
