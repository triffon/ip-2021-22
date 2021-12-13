#include <iostream>
#include <algorithm>    // std::min

using namespace std;

const int MAX_ROWS = 128;
const int MAX_COLS = 128;

void fillMatrix( int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    for ( unsigned row = 0; row < rowsCnt; row++ )
    {
        for ( unsigned col = 0; col < colsCnt; col++ )
        {
            cin >> mat[ row ][ col ];
        }
    }
}

void printFormatted( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    for ( unsigned row = 0; row < rowsCnt; row++ )
    {
        for ( unsigned col = 0; col < colsCnt; col++ )
        {
            cout << mat[ row ][ col ] << '\t';
        }
        cout << '\n';
    }
}

int diagonalSum( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    unsigned    minCnt  = min( rowsCnt, colsCnt );
    int         sum     = 0;

    for ( unsigned i = 0; i < minCnt; i++ )
        sum += mat[ i ][ i ];

    return sum;
}

int secondDiagonalProduct( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    unsigned    minCnt  = min( rowsCnt, colsCnt );
    int         prod    = 1;

    for ( unsigned i = 0; i < minCnt; i++ )
        prod *= mat[ i ][ colsCnt - 1 - i ];

    return prod;
}

int justUnderDiagonalSum( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    unsigned    minCnt  = min( rowsCnt, colsCnt );
    int         sum     = 0;

    for ( unsigned i = 1; i < minCnt; i++ )
        sum += mat[ i ][ i - 1 ];

    return sum;
}

int allUnderDiagonalSum( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    int sum = 0;

    for ( unsigned row = 1; row < rowsCnt; row++ )
    {
        for ( unsigned col = 0; col < row; col++ )
            sum += mat[ row ][ col ];
    }

    return sum;
}

void printMatrixSum( const int lhsMat[][ MAX_COLS ], const int rhsMat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    for ( unsigned row = 0; row < rowsCnt; row++ )
    {
        for ( unsigned col = 0; col < colsCnt; col++ )
        {
            cout << lhsMat[ row ][ col ] + rhsMat[ row ][ col ] << '\t';
        }
        cout << '\n';
    }
}

void printTranspose( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    for ( unsigned col = 0; col < colsCnt; col++ )
    {
        for ( unsigned row = 0; row < rowsCnt; row++ )
        {
            cout << mat[ row ][ col ] << '\t';
        }
        cout << '\n';
    }
}

void multiplyMatrices( 
    const int lhsMat[][ MAX_COLS ], 
    const int rhsMat[][ MAX_COLS ], 
    unsigned lhsRowsCnt, 
    unsigned commonCnt, 
    unsigned rhsColsCnt, 
    int outMat[][ MAX_COLS ] )
{
    for ( unsigned lrow = 0; lrow < lhsRowsCnt; lrow++ )
    {
        for ( unsigned rcol = 0; rcol < rhsColsCnt; rcol++ )
        {
            outMat[ lrow ][ rcol ] = 0;
            for ( unsigned ci = 0; ci < commonCnt; ci++ )
                outMat[ lrow ][ rcol ] += lhsMat[ lrow ][ ci ] * rhsMat[ ci ][ rcol ];
        }
    }
}

bool isMagicSquare( const int mat[][ MAX_COLS ], unsigned rowsCnt, unsigned colsCnt )
{
    if ( rowsCnt != colsCnt )
        return false;

    int diagSum     = diagonalSum( mat, rowsCnt, colsCnt );
    int secDiagSum  = 0;

    for ( unsigned i = 0; i < rowsCnt; i++ )
        secDiagSum += mat[ i ][ colsCnt - 1 - i ];

    if ( diagSum != secDiagSum )
        return false;

    int rowSum;
    int colSum;
    for ( unsigned row = 0; row < rowsCnt; row++ )
    {
        rowSum = 0;
        colSum = 0;
        for ( unsigned col = 0; col < colsCnt; col++ )
        {
            rowSum += mat[ row ][ col ];
            colSum += mat[ col ][ row ];
        }

        if ( rowSum != diagSum || colSum != diagSum )
            return false;
    }

    return true;
}

int main()
{
    int mat[ MAX_ROWS ][ MAX_COLS ];
    unsigned rows, cols;

    cin >> rows >> cols;

    fillMatrix( mat, rows, cols );

    cout << '\n';

    // Task 1
    printFormatted( mat, rows, cols );

    // Task 2
    cout << "\nDiagonal sum:\t\t\t" << diagonalSum( mat, rows, cols ) << '\n';

    // Task 3
    cout << "Second diagonal product:\t" << secondDiagonalProduct( mat, rows, cols ) << '\n';

    // Task 4
    cout << "Just under diagonal sum:\t" << justUnderDiagonalSum( mat, rows, cols ) << '\n';
    cout << "All under diagonal sum: \t" << allUnderDiagonalSum( mat, rows, cols ) << '\n';

    // Task 5
    cout << "\nSum of matrix with itself:\n";
    printMatrixSum( mat, mat, rows, cols );

    // Task 6
    cout << "\nPrint transpose:\n";
    printTranspose( mat, rows, cols );

    // Task 7
    int prodMat[ MAX_ROWS ][ MAX_COLS ] = { 0, };
    multiplyMatrices( mat, mat, rows, cols, cols, prodMat );
    cout << "\nMatrix times Matrix:\n";
    printFormatted( prodMat, rows, cols );

    // Task 8
    cout << "\nIs magic square:\t\t" << boolalpha << isMagicSquare( mat, rows, cols ) << '\n';

    return 0;
}
