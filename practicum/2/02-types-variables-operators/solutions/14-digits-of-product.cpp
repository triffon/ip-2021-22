#include <iostream>
#include <cmath>

using namespace std;

/** 
 *  Задача 14.
 * Прочетете три цели положителни числа в интервала (0; 16384].
 * Намерете броя на цифрите на произведението им.
 */

int main()
{
    unsigned int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    // Не работи за числа "към края на интервала" -> overflow
    // cout << (int) log10(num1 * num2 * num3) + 1;

    // Maths: log(a*b) = log(a) + log(b)
    cout << (int) (log10(num1) + log10(num2) + log10(num3)) + 1;

    return 0;
}
