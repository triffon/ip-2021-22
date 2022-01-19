#include <iostream>

// Inserts an element at a position keeping the order of the array
bool insertAt(int* arr, int& size, int element, int position);
// Reads the given array from the console
void readArray(int* arr, int size);
// Prints the given array
void printArray(const int arr[], int size);

const int MAX_SIZE = 1024;

int main()
{
    int size;
    int arr[MAX_SIZE];

    std::cout << "Enter array size: ";
    std::cin >> size;

    std::cout << "Enter the elements of the array: ";
    readArray(arr, size);

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            insertAt(arr, size, sum, i + 1);
            i++;
        } else {
            sum += arr[i];
        }
    }

    printArray(arr, size);

    return 0;
}




bool insertAt(int* arr, int& size, int element, int position)
{
    if (position > size || position < 0 || size + 1 > MAX_SIZE)
        return false;

    for (int i = size; i > position; --i)
        arr[i] = arr[i - 1];

    arr[position] = element;
    ++size;

    return true;
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
