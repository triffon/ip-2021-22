#include <iostream>

using namespace std;

/**
 *  Задача 10. Напишете програма, която намира най-голямото
 * произведение, което може да се получи след поставянето
 * на знак за умножение между две от цифрите на цяло
 * положително трицифрено число.
 *  Примерен вход:  358
 *  Примерен изход: 280
 */

int main()
{
    int num;
    cin >> num;

    short digit1 = num / 100;
    short digit2 = (num / 10) % 10;
    short digit3 = num % 10;

    // Двата начина за поставяне на знака за умножение
    // (числото е от примера горе)
    int firstWay  = (digit1 * 10 + digit2) * digit3;    // 35 * 8
    int secondWay = digit1 * (digit2 * 10 + digit3);    // 3 * 58

    cout << max(firstWay, secondWay);

    return 0;
}
