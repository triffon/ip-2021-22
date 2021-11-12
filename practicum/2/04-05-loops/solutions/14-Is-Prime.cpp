#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num = 0;
    cin >> num;

    if (num < 0)
    {
        cout << "Wrong input!" << '\n';
        return 1;
    }

    if (num == 1)
    {
        cout << num << " is not a prime number" << '\n';
        return 0;
    }

    if (num == 2)
    {
        cout << num << " is a prime number" << '\n';
        return 0;
    }

    bool    isPrime = (num % 2 == 1);
    int     sqrtNum = round( sqrt(num) );
    for (int i = 3; isPrime && i <= sqrtNum; i += 2)
        if (num % i == 0)
            isPrime = false;

    cout
        << num << (isPrime ? " is a " : " is not ")
        << "a prime number" << '\n';

    return 0;
}
