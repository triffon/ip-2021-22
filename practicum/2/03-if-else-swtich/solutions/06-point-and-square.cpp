#include <iostream>
#include <cmath>

using namespace std;

/**
 * По подадена точка A и страна на квадрат центриран в центъра на
 * координатната система да се определи взаимното им положение.
 */
int main()
{
    float ptX, ptY, sqSide;
    cout << "Enter point's coords: ";
    cin >> ptX >> ptY;

    cout << "Enter square's side: ";
    cin >> sqSide;

    // Константа за проверката за равенство на
    // две дробни числа с точност епсилон.
    const float EPS = 0.0001;

    float halfSide  = sqSide / 2;
    float absPtX    = abs( ptX );
    float absPtY    = abs( ptY );

    cout << "Point A(" << ptX << ", " << ptY << ") ";

    // Сравнение на дробни числа с точност EPS:
    //  x == y    =>    |x - y| < EPS
    //  x <= y    =>    x < y + EPS
    //  x >= y    =>    x > y - EPS

    // В нашия случай:
    //  absPtX == halfSide    =>    |absPtX - halfSide| < EPS
    // Ако разликата между |Х| на точката и половината от дължината на страната
    // на квадрата е по-малка от епсилон. (т.е. са почти равни),
    // то Х на точката лежи върху лявата или дясната страна на квадрата.
    // 
    // Остава само да проверим къде се намира Y координатата.
    //  Y in [-halfSide; halfSide]      =>
    //  Y >= -halfSide && Y <= halfSide =>
    //  |Y| <= halfSide                 =>
    //  |Y| < halfSide + EPS

    // ВАЖНО: При сравняване на стойности с точност първо правим проверките с
    // точност, след това правим проверките без точност, ако са нужни!

    // Упсловието на следния if да се чете така:
    //  Ако |Х| == страната, а Y е [-страната; страната]
    //      ИЛИ
    //  Ако |Y| == страната, а X е [-страната; страната]
    if (    ( (abs(absPtX - halfSide) < EPS) && (absPtY < halfSide + EPS) )
       ||   ( (abs(absPtY - halfSide) < EPS) && (absPtX < halfSide + EPS) ) )
    {
        cout << "is ON the rectangle";
    }
    else if ( absPtX < halfSide && absPtY < halfSide )
    {
        cout << "is INSIDE the rectangle";
    }
    else
    {
        cout << "is OUTSIDE the rectangle";
    }

    return 0;
}
