#include <iostream>

using namespace std;

// Task 4: Calculates and returns the factorial of num.
unsigned long long factorial( unsigned num )
{
    unsigned long long resFactorial = 1;
    for ( unsigned i = num; i > 1; i-- )
        resFactorial *= i;

    return resFactorial;
}

// Task 5: Calculates and returns the triple factorial of num.
unsigned long long tripleFactorial( unsigned num )
{
    unsigned long long resFactorial = 1;

    // Using int instead of unsigned int
    // as unsigned may underflow with a step of 3
    // Note: Assigning unsigned to int may overflow
    for ( int i = num; i > 1; i -= 3 )
        resFactorial *= i;

    return resFactorial;
}

// Task 6: Calculates and returns num to the power of pow.
double power( double num, unsigned pow )
{
    double res = 1.0;
    for ( unsigned i = 0; i < pow; i++ )
        res *= num;

    return res;
}

// Task 7: Calculates and returns the n-th fibonacci number.
unsigned long long fibonacci( unsigned nth )
{
    if ( nth <= 1 )
        return nth;

    unsigned long long prevNum = 1;
    unsigned long long nextNum = 1;
    for ( unsigned i = 2; i < nth; i++ )
    {
        swap( prevNum, nextNum );
        nextNum += prevNum;
    }

    return nextNum;
}

// Task 8: Calculates and prints the binary representation of num.
void printBinary( unsigned num )
{
    short binArrRepr[ sizeof(num) * 8 ];
    int binLen = 0;
    while ( num > 0 )
    {
        binArrRepr[ binLen ] = num % 2;
        num /= 2;
        ++binLen;
    }

    if ( binLen == 0 )
    {
        cout << 0;
    }
    else
    {
        for ( int i = binLen - 1; i >= 0; i-- )
            cout << binArrRepr[ i ];
    }
}

// Task 8 Alternative: Calculates and prints the binary representation of num recursively.
void printBinaryRec( unsigned num )
{
    if ( num > 0 )
    {
        printBinaryRec( num / 2 );
        cout << num % 2;
    }
}

// Task 9: Calculates and returns the Greatest Common Divisor.
unsigned gcd( unsigned fnum, unsigned snum )
{
    if ( fnum == 0 )
        return snum;

    if ( snum == 0 )
        return fnum;

    while ( fnum != snum )
    {
        if ( fnum > snum )
            fnum -= snum;
        else
            snum -= fnum;
    }

    return fnum;
}

// Task 10: Compares two strings lexicographically.
int strCmp( const char str1[], const char str2[] )
{
    bool areSame = false;
    int index = 0;
    while ( str1[ index ] != '\0' && areSame )
    {
        if ( str1[ index ] == str2[ index ] )
            ++index;
        else
            areSame = false;
    }

    return str1[ index ] - str2[ index ];
}

// Task 10 Alternative: Compares two strings lexicographically with pointers.
int strCmpP( const char* str1, const char* str2 )
{
    while ( *str1 && *str1 == *str2 )
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

// Task 11: Print first 'rows' rows of the Pascal triangle.
void printPascalTriangle( int rows )
{
    int coef = 1;
    for ( int row = 0; row < rows; row++ )
    {
        for ( int i = 1; i <= rows - row; i++ )
            std::cout << '\t';

        for ( int ind = 0; ind <= row; ind++ )
        {
            if ( row == 0 || ind == 0 )
                coef = 1;
            else
                coef = coef * ( row - ind + 1 ) / ind;

            cout << coef << "\t\t";
        }

        cout << '\n';
    }
}

//------------------------------------------------------------------------------
int main()
{
    cout << "Factorial: \t\t" << factorial( 8 ) << '\n';
    cout << "Triple factorial: \t" << tripleFactorial( 8 ) << '\n';
    cout << "Power: \t\t\t" << power( 3, 8 ) << '\n';
    cout << "Fibonacci: \t\t" << fibonacci( 11 ) << '\n';
    cout << "Binary: \t\t"; printBinary( 250 ); cout << '\n';
    cout << "BinaryRec: \t\t"; printBinaryRec( 250 ); cout << '\n';
    cout << "GCD: \t\t\t" << gcd( 2145, 1235 ) << '\n';
    cout << "strCmp: \t\t" << strCmp( "fmi", "unwe" ) << '\n';
    cout << "strCmpP: \t\t" << strCmpP( "fmi", "unwe" ) << '\n';
    cout << "Pascal Triangle:\n"; printPascalTriangle( 8 ); cout << '\n';

    return 0;
}
