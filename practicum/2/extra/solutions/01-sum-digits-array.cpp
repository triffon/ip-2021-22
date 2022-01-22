#include <iostream>
#include <cmath>

int sumDigits( int num )
{
    if ( num == 0 )
        return 0;

    return std::abs( num % 10 ) + sumDigits( num / 10 );
}

void deleteMat( int**& mat, int size )
{
    for ( int i = 0; i < size; i++ )
        delete[] mat[ i ];

    delete[] mat;
    mat = nullptr;
}

int main()
{
    unsigned cnt;
    std::cin >> cnt;

    int* arr = new ( std::nothrow ) int[ cnt ];
    if ( arr == nullptr )
    {
        std::cout << "Not enough memory!\n";
        return 1;
    }

    // Input
    for ( int i = 0; i < cnt; i++ )
        std::cin >> arr[ i ];
    
    // Finding max sum
    int maxSum = sumDigits( arr[ 0 ] );
    for ( int i = 1; i < cnt; i++ )
    {
        int currSum = sumDigits( arr[ i ] );
        if ( maxSum < currSum )
            maxSum = currSum;
    }

    // Finding cnts
    int* cntsArr = new ( std::nothrow ) int[ maxSum + 1 ];
    if ( !cntsArr ) // same as cntsArr == nullptr
    {
        delete[] arr;
        std::cout << "no mem\n";
        return 1;
    }

    int* cntsArrOriginal = new ( std::nothrow ) int[ maxSum + 1 ];
    if ( !cntsArrOriginal ) // same as cntsArr == nullptr
    {
        delete[] arr;
        delete[] cntsArr;
        std::cout << "no mem\n";
        return 1;
    }

    for ( int i = 0; i <= maxSum; i++ )
        cntsArr[ i ] = 0;

    for ( int i = 0; i < cnt; i++ )
    {
        int ind = sumDigits( arr[ i ] );
        cntsArr[ ind ] += 1;
        cntsArrOriginal[ ind ] = cntsArr[ ind ];
    }

    // Creating the output matrix
    int** outputMat = new ( std::nothrow ) int* [ maxSum + 1 ];
    if ( !outputMat )
    {
        delete[] arr;
        delete[] cntsArr;
        delete[] cntsArrOriginal;
        std::cout << "no mem\n";
        return 1;
    }

    for ( int i = 0; i <= maxSum; i++ )
    {
        outputMat[ i ] = new ( std::nothrow ) int[ cntsArr[ i ] ];
        if ( !outputMat[ i ] )
        {
            delete[] arr;
            delete[] cntsArr;
            delete[] cntsArrOriginal;
            deleteMat( outputMat, i );

            std::cout << "no mem\n";
            return 1;
        }
    }

    for ( int i = 0; i < cnt; i++ )
    {
        int currSum = sumDigits( arr[ i ] );
        int innerIndex = cntsArr[ currSum ] - 1;
        cntsArr[ currSum ]--;
        outputMat[ currSum ][ innerIndex ] = arr[ i ];
    }

    for ( int i = 0; i <= maxSum; i++ )
    {
        std::cout << i << ": ";
        for ( int j = 0; j < cntsArrOriginal[ i ]; j++ )
            std::cout << outputMat[ i ][ j ] << " ";
        std::cout << '\n';
    }

    // Deleting allocated memory
    deleteMat( outputMat, maxSum + 1 );

    delete[] cntsArrOriginal;
    delete[] cntsArr;
    delete[] arr;

    return 0;
}
