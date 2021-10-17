#include <iostream>
#include <cmath>

using namespace std;

/** 
 *  Задача 12. Прочетете координати на 5 точки - естествени числа
 * в интервала [0; 100]. Изведете радиуса на минимална покриваща
 * окръжност, чийто център е с координати (0,0).
 *  Пример: (1, 2) (3, 4) (4, 2) (2, 2) (2, 0)
 *  Изход:  r = 5
 *
 *  Забележка: Приемаме, че входът ще бъде само числата (без други символи)
 *  т.е. Вход:  1 2 3 4 4 2 2 2 2 0
 *       Изход: r = 5
 */

int main()
{
    // Забележка: Повтарянето на код е лоша практика!
    // Но за момента не сме изучавали начин да се справим с това.

    short x1, y1;
    short x2, y2;
    short x3, y3;
    short x4, y4;
    short x5, y5;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cin >> x5 >> y5;

    int sqRadius = 0;
    sqRadius = max( sqRadius, x1 * x1 + y1 * y1 );
    sqRadius = max( sqRadius, x2 * x2 + y2 * y2 );
    sqRadius = max( sqRadius, x3 * x3 + y3 * y3 );
    sqRadius = max( sqRadius, x4 * x4 + y4 * y4 );
    sqRadius = max( sqRadius, x5 * x5 + y5 * y5 );

    double radius = sqrt( sqRadius );

    cout << "r = " << radius;

    return 0;
}
