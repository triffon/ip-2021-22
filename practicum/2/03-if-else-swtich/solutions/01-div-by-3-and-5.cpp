#include <iostream>

using namespace std;

/**
 * Прочетете цяло число от конзолата и изведете дали се дели на 5, на 3
 * или нито едно от двете.
 */
int main()
{
    int num;
    cin >> num;

    bool isDivBy5   = num % 5 == 0;
    bool isDivBy3   = num % 3 == 0;

    if ( isDivBy3 && isDivBy5 )
    {
        cout << num << " is divisible by 5 and 3.";
    }
    else if ( isDivBy3 )
    {
        cout << num << " is divisible by 3.";
    }
    else if ( isDivBy5 )
    {
        cout << num << " is divisible by 5.";
    }
    else
    {
        cout << num << " is not divisible by 5 or 3.";
    }

    return 0;
}
