#include <iostream>

void selectionSort(int* arr, int n);
bool sumExists2(const int* arr, int size, int sum);

const int MAX_SIZE = 1024;

int main()
{
    int arr[MAX_SIZE];
    int count, sum;
    std::cout << "Enter the searched sum: ";
    std::cin >> sum;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> count;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < count; i++)
        std::cin >> arr[i];

    std::cout << (findSumPair(arr, count, sum) ? "Yes" : "No");

    return 0;
}


void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int currMinIndex = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[currMinIndex])
                currMinIndex = j;

        if (i != currMinIndex)
            std::swap(arr[i], arr[currMinIndex]);
    }
}


bool findSumPair( const int* arr, int size, int sum )
{
    for ( int i = 0; i < size; i++ )
    {
        for ( int j = i + 1; j < size; j++ )
        {
            if ( i != j && arr[ i ] + arr[ j ] == sum )
                return true;
        }
    }

    return false;
}


bool findSumPair2(int* arr, int size, int sum)
{
    selectionSort(arr, size);

    int lIndex = 0;
    int rIndex = size - 1;

    while (arr[lIndex] + arr[rIndex] != sum && lIndex != rIndex)
    {
        if (arr[lIndex] + arr[rIndex] < sum)
            lIndex++;
        else
            rIndex--;
    }

    return arr[lIndex] + arr[rIndex] == sum;
}
