#include <iostream>

// Selection sort
void selectionSort(int* arr, int size);
// Reads the given array from the console
void readArray(int* arr, int size);
// Prints the given array
void printArray(const int* arr, int size);

const int MAX_SIZE = 1024;

int main()
{
    int size;
    int arr[MAX_SIZE];

    std::cout << "Enter array size: ";
    std::cin >> size;

    std::cout << "Enter the elements of the array: ";
    readArray(arr, size);

    selectionSort(arr, size);

    printArray(arr, size);

    return 0;
}


void readArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}


void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
}


void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        int currMaxIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] > arr[currMaxIndex])
                currMaxIndex = j;
        if (i != currMaxIndex)
            std::swap(arr[i], arr[currMaxIndex]);
    }
}


void bubbleSort( int* arr, int size )
{
    for ( int iter = 0; iter < size; iter++ )
    {
        bool isSorted = true;

        for ( int ind = 0; ind < size - iter - 1; ind++ )
        {
            if ( arr[ ind ] < arr[ ind + 1 ] )
            {
                std::swap( arr[ ind ], arr[ ind + 1 ] );
                isSorted = false;
            }
        }

        if ( isSorted )
            return;
    }
}
