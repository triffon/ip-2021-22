#include <iostream>

using namespace std;

// Task 1: Returns the absolute value of the given number
int Abs( int num )
{
    return num < 0 ? -num : num;
}

// Task 2: Returns the smaller of two numbers
int Min( int num1, int num2 )
{
    return num1 < num2 ? num1 : num2;
}

// Task 2: Returns the greater of two numbers
int Max( int num1, int num2 )
{
    return num1 > num2 ? num1 : num2;
}

// Task 2 bonus: Returns the smallest of all elements in an array
int Min( int arr[], int size )
{
    if ( size <= 0 )
        return 0;

    int resMin = arr[ 0 ];

    for ( int i = 1; i < size; i++ )
        if ( arr[ i ] < resMin )
            resMin = arr[ i ];

    return resMin;
}

// Task 3: Compares two real numbers with eps precision
bool AreEqual( double num1, double num2, double eps = 0.00001 )
{
    return Abs( num1 - num2 ) < eps;
}

//------------------------------------------------------------------------------
int main()
{
    //cout << Abs( 3 ) << '\n';
    //cout << Abs( -4 ) << '\n';

    //cout << Min( 2, 3 ) << '\n';
    //cout << Max( 2, 3 ) << '\n';

    const int   MAX         = 128;
    const int   ACTUAL_SIZE = 6;
    int         arr[ MAX ]  = { 2, -3, 5, 1, 9, -1 };

    cout << Min( arr, ACTUAL_SIZE ) << '\n';

    double          num1    = 3.217;
    double          num2    = 1.333;
    const double    EPS     = 3.042;

    cout << ( AreEqual( num1, num2 ) ? "true" : "false" ) << '\n';
    cout << ( AreEqual( num1, num2, EPS ) ? "true" : "false" ) << '\n';

    return 0;
}
