#include <iostream>

// 3. Напишете рекурсивна функция, която по подаден масив и размер
// връща най-голямото число в масива.
// Версия с указатели и допълнителни sanity checks.
const int* max( const int* arr, int size )
{
    if ( size < 1 )
        return nullptr;

    if ( size == 1 )
        return arr;

    const int* pres = max( arr + 1, size - 1 );
    return *arr > *pres ? arr : pres;
}

// 4. Напишете рекурсивна функция, която по подадено число
// изчислява факториела му.
unsigned int fact( unsigned int num )
{
    if ( num == 0 )
        return 1;

    return num * fact( num - 1 );
}

// 4. Версия с опашкова рекурсия
unsigned int fact2( unsigned int num, unsigned int res = 1 )
{
    if ( num == 0 )
        return res;

    return fact2( num - 1, res * num ); // Опашкова рекурсия
}

// Функцията, но само с 1 аргумент
unsigned int fact2Wrappper( unsigned int num )
{
    return fact2( num, 1 );
}

// 5. Напишете рекурсивна функция strlen.
int StrLen( const char* str )
{
    if ( *str == '\0' ) // str[i] <=> *(str + i)
        return 0;

    return 1 + StrLen( str + 1 );
}

// 6. Напишете рекурсивна функция strcpy.
void StrCpy( char* dest, const char* src )
{
    if ( *src == '\0' ) // *str == '\0' <=> !*str
    {
        *dest = '\0';
        return;
    }

    *dest = *src;
    StrCpy( dest + 1, src + 1 ); // Опашкова рекурсия
}

// 7. Напишете рекурсивна функция, която по подадено цяло число
// връща сумата на цифрите на числото.
int sumOfDigits( int num )
{
    if ( num == 0 )
        return 0;

    return num % 10 + sumOfDigits( num / 10 );
}

// Връща индекса на минималния елемент от масива.
int arrMinIndex( const int* arr, int size )
{
    if ( size == 1 )
        return 0;

    int nextMinIndex = arrMinIndex( arr, size - 1 );
    return ( arr[ size - 1 ] < arr[ nextMinIndex ] ) ? size - 1 : nextMinIndex;
}

// 8. Напишете рекурсивна функция за сортиране с пряка селекция.
void selectionSort( int* arr, int size )
{
    if ( size <= 1 )
        return;

    int minIndex = arrMinIndex( arr, size );
    if ( minIndex != 0 )
        std::swap( *arr, arr[ minIndex ] );

    selectionSort( arr + 1, size - 1 ); // Опашкова рекурсия
}

// 9. Напишете рекурсивна функция за двоично търсене.
bool binarySearch( const int* sortedArr, int size, int target )
{
    if ( size <= 0 )
        return false;

    const int* pMid = sortedArr + size / 2;

    if ( *pMid == target )
        return true;

    if ( *pMid < target )
        return binarySearch( pMid + 1, size / 2, target );  // Опашкова рекурсия

    return binarySearch( sortedArr, size / 2, target );     // Опашкова рекурсия
}
