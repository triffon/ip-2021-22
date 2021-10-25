#include <iostream>

using namespace std;

/**
 * Въвежда се час и се извежда "Good morning!", "Good day!", "Good evening!"
 * или "Good night!". Проверете дали часът е валиден!
 */
int main()
{
    short hour, minutes;
    char delim;

    cin >> hour >> delim >> minutes;

    if ( delim != ':' )
    {
        cout << "The delimiter should be ':' !";
        return 1;
    }

    if ( hour < 0 || hour > 23 || minutes < 0 || minutes > 59 )
    {
        cout << "Wrong time!";
        return 2;
    }

    const int MINS_IN_H = 60;   // 60 minutes in one hour

    // Randomly chosen hours
    const int START_MORNING_TIME    = 5 * MINS_IN_H;    // 05:00
    const int END_MORNING_TIME      = 10 * MINS_IN_H;   // 10:00
    const int END_DAY_TIME          = 16 * MINS_IN_H;   // 16:00
    const int END_EVENING_TIME      = 20 * MINS_IN_H;   // 20:00

    int timeInMins = hour * 60 + minutes;
    if ( timeInMins > START_MORNING_TIME && timeInMins <= END_MORNING_TIME )
    {
        cout << "Good morning!";
    }
    else if ( timeInMins > END_MORNING_TIME && timeInMins <= END_DAY_TIME )
    {
        cout << "Good day!";
    }
    else if ( timeInMins > END_DAY_TIME && timeInMins <= END_EVENING_TIME )
    {
        cout << "Good evening!";
    }
    else
    {
        cout << "Good night!";
    }

    return 0;
}
