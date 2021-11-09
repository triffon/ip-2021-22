// Напишете програма, която по въведено цяло положително число от конзолата
// извежда дали може да бъде записано като сбор от точно две прости числа.
#include <iostream>

using namespace std;

bool isPrime( unsigned int num );

int main()
{
    unsigned int num;
    cin >> num;

    if ( num < 4 )
    {
        cout << "No.";
    }
    else
    { 
        // if N is even directly return true;
        // Goldbach's conjecture has been proven for the numbers
        // that can be represented by C++’s scalar data types
        if ( num % 2 == 0 )
            cout << "Yes.";

        // If N is odd, then one prime must
        // be 2. All other primes are odd
        // and cannot have a pair sum as even.
        else
            cout << ( isPrime( num - 2 ) ? "Yes." : "No." );
    }

    return 0;
}


bool isPrime( unsigned int num )
{
    if ( num == 2 )
        return true;

    if ( num % 2 == 0 )
        return false;

    unsigned int sqrtNum = round( sqrt( num ) );

    for ( unsigned int div = 3; div <= sqrtNum; div += 2 )
    {
        if ( num % div == 0 )
            return false;
    }

    return true;
}
