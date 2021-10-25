#include <iostream>

using namespace std;

/**
 * Прочетете 5-цифрено число. Изведете 1 ако е палиндром и 0 ако не е.
 */
int main()
{
    int num;
    cin >> num;

    int digit1 = num / 10000;
    int digit2 = ( num / 1000 ) % 10;
    //  digit3 не е от значение
    int digit4 = ( num / 10 ) % 10;
    int digit5 = num % 10;

    bool isPalindrome = ( digit1 == digit5 ) && ( digit2 == digit4 );
    cout << isPalindrome;

    return 0;
}
