#include <iostream>

using namespace std;

/**
 * Прочетете 4-цифрено число. Изведете го в обратен ред.
 */
int main()
{
    int num;
    cin >> num;

    int digit1 = num / 1000;
    int digit2 = ( num / 100 ) % 10;
    int digit3 = ( num / 10 ) % 10;
    int digit4 = num % 10;

    cout << digit4 << digit3 << digit2 << digit1;

    return 0;
}
