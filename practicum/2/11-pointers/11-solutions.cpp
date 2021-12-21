#include <iostream>

const int* findMin( const int* arr, int size );
int myStrLen( const char* str );
void myStrCpy( char* dest, const char* src );
int myStrCmp( const char* lhs, const char* rhs );
int myStriCmp( const char* lhs, const char* rhs );
void myStrCat( char* dest, const char* src );
const char* myStrChr( const char* str, char ch );
char* myStrChr( char* str, char ch );
const char* myStrrChr( const char* str, char ch );
char* myStrrChr( char* str, char ch );

//------------------------------------------------------------------------------
int main()
{
    /// Task 1
    //const int MAX = 64;
    //int arr[ MAX ];
    //int cnt;

    //std::cin >> cnt;

    //for ( int i = 0; i < cnt; i++ )
    //    std::cin >> arr[ i ];

    //const int* pMin = findMin( arr, cnt );
    //if ( pMin )
    //{
    //    std::cout << "Min element: " << *pMin << '\n';
    //}
    //else
    //{
    //    std::cout << "Array has no min element!\n";
    //}


    /// Task 2
    const int STR_MAX = 64;
    char str[ STR_MAX ];
    char str2[ STR_MAX ];

    std::cin.getline( str, STR_MAX );

    std::cout << "strlen:\t\t\t\t" << myStrLen( str ) << '\n';
    myStrCpy( str2, str );
    std::cout << "strcpy:\t\t\t\t" << str2 << '\n';
    std::cout << "strcmp with \"fmi\":\t\t" << myStrCmp( str, "fmi" ) << '\n';
    std::cout << "stricmp with \"fmi\":\t\t" << myStriCmp( str, "fmi" ) << '\n';
    myStrCat( str2, "fmi" );
    std::cout << "strcat with \"fmi\":\t\t" << str2 << '\n';

    char* pCh = myStrrChr( str2, 'f' );
    if ( pCh )
        *pCh = '5';

    std::cout << "strrchr repl 'f' w\\ '5':\t" << str2 << '\n';

    //const char* pConstCh = myStrChr( "fmi", 'm' );
    //if ( pConstCh )
    //    *pConstCh = '3';    // Can't be done!


    /// Practice code
    /*
    int num;
    int num2;

    num = 5;
    num2 = 6;

    int* pToNum = &num;

    *pToNum = 42;

    cout << num << '\n';
    cout << num2 << '\n';
    cout << *pToNum;
    */
    return 0;
}
//------------------------------------------------------------------------------

const int* findMin( const int* arr, int size )
{
    if ( size <= 0 )
        return nullptr;

    const int* pMin = arr;

    for ( int i = 1; i < size; i++ )
    {
        /// Variant 1
        if ( arr[ i ] < *pMin )
            pMin = arr + i;

        /// Variant 2
        //if ( arr[ i ] < *pMin )
        //    pMin = &arr[ i ];

        // Note: arr[ i ] <=> *(arr + i)
        // &arr[ i ] <=> &*(arr + i) <=> arr + i
    }

    return pMin;
}


int myStrLen( const char* str )
{
    /// Variant 1
    int cnt = 0;
    while ( *str )
    {
        ++str;
        ++cnt;
    }

    return cnt;

    /// Variant 2
    //const char* pCurr = str;
    //while ( *pCurr )
    //    ++pCurr;
    //
    //return pCurr - str;
}


void myStrCpy( char* dest, const char* src )
{
    while ( *src )
    {
        *dest = *src;
        ++dest;
        ++src;
    }

    *dest = '\0';
}


int myStrCmp( const char* lhs, const char* rhs )
{
    while ( *lhs && *lhs == *rhs )
    {
        ++lhs;
        ++rhs;
    }

    return *lhs - *rhs;
}


char to_lower( char ch )
{
    if ( ch >= 'A' && ch <= 'Z' )
        return ch + 'a' - 'A';

    return ch;
}


int myStriCmp( const char* lhs, const char* rhs )
{
    while ( *lhs && to_lower( *lhs ) == to_lower( *rhs ) )
    {
        ++lhs;
        ++rhs;
    }

    return *lhs - *rhs;
}


void myStrCat( char* dest, const char* src )
{
    while ( *dest )
        ++dest;

    myStrCpy( dest, src );
}


const char* myStrChr( const char* str, char ch )
{
    while ( *str )
    {
        if ( *str == ch )
            return str;

        ++str;
    }

    return nullptr;
}


char* myStrChr( char* str, char ch )
{
    while ( *str )
    {
        if ( *str == ch )
            return str;

        ++str;
    }

    return nullptr;

    // Note: Following is a way to avoid the
    // code duplication but it gets a little ugly.
    // 
    // Variant 2 - Warning: C++ magic ahead! Use at your own risk!
    // 
    //return const_cast<char*>( myStrChr( (const char*) str, ch ) );
    //
    // Note: Always use the const version to implement
    // the non-const version and NOT the other way around!
}


const char* myStrrChr( const char* str, char ch )
{
    const char* pRes = nullptr;

    while ( *str )
    {
        if ( *str == ch )
            pRes = str;

        ++str;
    }

    return pRes;
}


char* myStrrChr( char* str, char ch )
{
    char* pRes = nullptr;

    while ( *str )
    {
        if ( *str == ch )
            pRes = str;

        ++str;
    }

    return pRes;

    // Variant 2 - No code duplication.
    // Warning: C++ magic ahead! Use at your own risk!
    //
    //return const_cast<char*>( myStrrChr( (const char*) str, ch ) );
}
