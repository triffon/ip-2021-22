#include <iostream>

using namespace std;

int main()
{
    const int MAX_CNT = 128;
    int arrSize;
    int arr[ MAX_CNT ];

    cin >> arrSize;

    // array input
    for ( int i = 0; i < arrSize; i++ )
        cin >> arr[ i ];

    /// 04. Напишете програма, която извежда средно аритметичното на
    ///     четните числа от масив.
    //int sum = 0;
    //int cnt = 0;
    //for ( int i = 0; i < arrSize; i++ )
    //{
    //    if ( arr[ i ] % 2 == 0 )
    //    {
    //        cnt++;
    //        sum += arr[ i ];
    //    }
    //}

    //cout << sum / (float)cnt;

    /// 05. Напишете програма, която събира числата на нечетните позиции в масив
    ///     и изважда числата на четните позиции в масива. Изведете резултата.
    //int sum = 0;
    //for ( int i = 0; i < arrSize; i++ )
    //{
    //    if ( i % 2 == 0 )
    //        sum -= arr[ i ];
    //    else
    //        sum += arr[ i ];
    //}

    //cout << sum;

    /// 06. Напишете програма, която извежда числата от масив, които се повтарят.
    //for ( int i = 0; i < arrSize; i++ )
    //{
    //    for ( int j = i + 1; j < arrSize; j++ )
    //    {
    //        if ( arr[ i ] == arr[ j ] )
    //        {
    //            cout << arr[ i ];
    //            break;
    //        }
    //    }
    //}

    /// 07. Напишете програма, която извежда елементите на масив без повторения.
    //for ( int i = 0; i < arrSize; i++ )
    //{
    //    bool isRepeating  = false;
    //    for ( int j = i - 1; j >= 0; j-- )
    //    {
    //        if ( arr[ i ] == arr[ j ] )
    //        {
    //            isRepeating = true;
    //            break;
    //        }
    //    }

    //    if ( ! isRepeating )
    //        cout << arr[ i ] << ' ';
    //}

    return 0;
}
