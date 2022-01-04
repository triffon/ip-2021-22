#include <iostream>

int main()
{
    /// Four important steps when using dynamically allocated memory

    int cnt;
    std::cin >> cnt;

    // Step 1: Request memory exact.
    int* arr = new (std::nothrow) int[ cnt ];

    // STEP 2: Check if the memory has been allocated!
    if ( !arr ) // equivalent to if ( arr == nullptr )
    {
        // NB! Don't forget to delete any previously allocated memory!

        std::cout << "There wasn't enough memory!\n";
        return 1;   // stop the execution of the program with error code 1
    }

    // Step 3: Do work.
    // use like any other array, for example:
    for ( int i = 0; i < cnt; i++ )
        std::cin >> arr[ i ];

    // ...

    for ( int i = 0; i < cnt; i++ )
        std::cout << arr[ i ] << ' ';
    std::cout << '\n';

    // STEP 4: Delete the allocated memory!
    delete[] arr;
    arr = nullptr;

    return 0;
}
