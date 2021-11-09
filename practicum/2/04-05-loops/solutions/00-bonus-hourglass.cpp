// Да се напише програма, която приема символ, брой на редове на горната 
// част и брой символи в средата и рисува контура на пясъчен часовник 
// чрез подадения символ. 
#include <iostream>

using namespace std;

int main()
{
    const char SPACE = ' ';
    char sym;
    int topSymbolsCnt;
    int midSymbolsCnt;

    cin >> sym >> topSymbolsCnt >> midSymbolsCnt;

    bool    topSymbolsEven  = topSymbolsCnt % 2 == 0;
    bool    midSymbolsEven  = midSymbolsCnt % 2 == 0;

    // top
    for ( int i = 0; i < topSymbolsCnt; i++ )
        cout << sym;
    cout << '\n';

    // rows
    int rowsLimit = topSymbolsCnt / 2 - midSymbolsCnt;
    if ( !midSymbolsEven )
        rowsLimit += 1;

    for ( int row = 0; row < rowsLimit; row++ )
    {
        for ( int j = 0; j <= row; j++ )
            cout << SPACE;

        cout << sym;

        int spacesLimit = topSymbolsCnt / 2 - row * 2 + midSymbolsCnt + 1;
        for ( int j = 0; j < spacesLimit; j++ )
            cout << SPACE;

        cout << sym;

        // We don't need to print spaces at the end of the line
        //for ( int j = 0; j <= row; j++ )
        //    cout << SPACE;

        cout << '\n';
    }

    if ( midSymbolsCnt == 0 && topSymbolsCnt % 2 != 0 )
    {
        for ( int j = 0; j < topSymbolsCnt / 2; j++ )
            cout << SPACE;

        cout << sym;
    }

    // TODO: Bottom part of hourglass

    return 0;
}
