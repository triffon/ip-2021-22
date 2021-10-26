#include <iostream>

using namespace std;

/**
 * Напишете програма, която при въвеждането на число от 1 до 7 извежда деня от седмицата.
 */
int main()
{
    int day;
    cin >> day;

    switch ( day )
    {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Not a week day";
            break;
    }

    return 0;
}
