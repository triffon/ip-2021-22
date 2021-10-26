#include <iostream>
#include <cmath>    // sqrt

using namespace std;

/**
 * Изчислете минималния покриващ правоъгълник на въведени 3 точкис целочислени
 * координати. Да се изведат координатите на горния ляв ъгъл на правоъгълника.
 * 
 * Забележка: В компютърната графика най-често оста Ox се увеличава надясно, а
 * пък оста Oy се увеличава надолу, т.е. нагоре и наляво x и y намаляват. 
 */
int main()
{
    // Координатите на точки могат да бъдат дробни числа.
    float x1, y1;
    float x2, y2;
    float x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    cout << '(' << min( x1, min(x2, x3) ) << ", " << min( y1, min(y2, y3) ) << ')';

    return 0;
}