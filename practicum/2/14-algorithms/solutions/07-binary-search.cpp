#include <iostream>

int binarySearch(const int arr[], int size, int target);
bool isPresent(const int arr[], int size, int target);

const int MAX_SIZE = 1024;

int main()
{
    int arr[MAX_SIZE];
    int size, target;
    std::cout << "Enter the target: ";
    std::cin >> target;
    std::cout << "Enter the array size: ";
    std::cin >> size;

    std::cout << "Enter the SORTED elements of the array: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    std::cout << (isPresent(arr, size, target) ? "Yes" : "No");

    return 0;
}


int binarySearch(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int index = -1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target)
        {
            index = middle;
            break;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return index;
}


bool isPresent(const int arr[], int size, int target)
{
    return binarySearch(arr, size, target) != -1;
}
