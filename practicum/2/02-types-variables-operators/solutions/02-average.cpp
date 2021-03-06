#include <iostream>

using namespace std;

/**
 * Прочетете три числа и извадете средно аритметичното им.
 */
int main()
{
    // Средно аритметичното е възможно да бъде дробно число,
    // а пък в условието не е казано какъв тип са числата.
    // Застраховаме се и за всички числа ползваме типа float.

    float num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    cout << ( num1 + num2 + num3 ) / 3.0f;

    // Забележка 1:
    //  Литералът 3     е от тип int
    //  Литералът 3.0   е от тип double
    //  Литералът 3.0f  е от тип float

    // Забележка 2:
    //  Нулите на дробните числа преди или след точката не са задължителни.
    //  Примери:
    //  1.      е 1.0 от тип double
    //  .2      е 0.2 от тип double
    //  3.f     е 3.0 от тип float
    //  ...

    return 0;
}
