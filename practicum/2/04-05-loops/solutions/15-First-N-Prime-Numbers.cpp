#include <iostream>

using namespace std;

int main()
{
    int N;
    unsigned num = 2;
    do
    {
        cout << "Enter the amount of primes: ";
        cin >> N;
    }
    while (N < 1);

    bool isPrime;
	unsigned primesFound = 0;
	while (primesFound < N)
	{
        if (num == 2) {
            isPrime = true;
            cout << num << ' ';
                ++primesFound;
            num = 3;
        } else {
            isPrime = (num % 2 == 1);
            int sqrtNum = round( sqrt(num) );
            for (int i = 3; isPrime && i <= sqrtNum; i += 2)
                if (num % i == 0)
                    isPrime = false;

            if (isPrime)
            {
                cout << num << ' ';
                ++primesFound;
            }
            num += 2;
        }
    }

    cout << '\n';

    return 0;
}
