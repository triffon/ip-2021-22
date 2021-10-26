#include <iostream>
#include <cmath>    // sqrt

using namespace std;

/**
 * Прочетете три цели числа от конзолата a, b и c - коефициенти наквадратното
 * уравнение ax^2 + bx + c = 0. Пресметнете и изведете на конзолата корените му.
 * Забележка: Ще считаме, че въведените стойности за a, b и c са
 * винаги такива, че уравнението има два реални корена.
 */
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    float sqrtDiscriminant = sqrt( b*b - 4*a*c );

    float firstRoot     = ( -b - sqrtDiscriminant ) / ( 2*a );
    float secondRoot    = ( -b + sqrtDiscriminant ) / ( 2*a );

    cout << "x1 = " << firstRoot << "\n";
    cout << "x2 = " << secondRoot << "\n";

    return 0;
}
