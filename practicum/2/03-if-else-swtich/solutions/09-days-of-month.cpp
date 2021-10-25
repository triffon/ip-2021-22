#include <iostream>

using namespace std;

/**
 * Напишете програма, която при въвеждането на число от 1 до 12 извежда
 * дали месеца има (28/29), 30 или 31 дни.
 */
int main()
{
    short month;

    cin >> month;

    switch ( month )
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            cout << 30;
            break;

        case 2:
            cout << "God knowns";
            break;

        default:
            cout << "Unknown month!";
            break;
    }

    return 0;
}
