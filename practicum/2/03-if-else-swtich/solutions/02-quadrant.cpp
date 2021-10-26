#include <iostream>

using namespace std;

/**
 * По подадена точка, да се определи в кой квадрант е тя.
 */
int main()
{
    // За целта на упражнението ще игнорираме факта, че
    // координатите на точка могат да бъдат дробни числа
    // и ще работим с целочислени (int).
    int x, y;
    cin >> x >> y;

    if ( x > 0 )
    {
        if ( y > 0 )
            cout << "First quadrant";
        else if ( y < 0 )
            cout << "Fourth quadrant";
        else
            cout << "Oy";
    }
    else if ( x < 0 )
    {
        if ( y > 0 )
            cout << "Second quadrant";
        else if ( y < 0 )
            cout << "Third quadrant";
        else
            cout << "Oy";
    }
    else // x is 0
    {
        if ( y != 0 )
            cout << "Ox";
        else
            cout << "O(0, 0)";
    }

    return 0;
}
