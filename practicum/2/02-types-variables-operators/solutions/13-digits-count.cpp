#include <iostream>
#include <cmath>

using namespace std;

/** 
 *  Задача 12.
 * Прочетете цяло положително число от конзолата и изведете броя на цифрите му.
 * (Бонус: Броя на цифрите на числото, записано в двоична бройна система)
 */

int main()
{
    unsigned int num;
    cin >> num;

    cout << (int) log10(num) + 1;

    return 0;
}
