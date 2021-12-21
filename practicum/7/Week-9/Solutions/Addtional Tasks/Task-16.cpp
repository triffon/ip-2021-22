#include <iostream>

const int MAX_ELEMENTS = 256;

void swap(int* a, int* b)
{

    int c = *a;
    *a = *b;
    *b = c;
}

void swapEvens(int* arr, int n)
{
    for (int i = 0; i < n / 2; i += 2)
    {
        swap(arr + i, arr + n - i);
    }
}

int main()
{
    int arr[MAX_ELEMENTS];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    swapEvens(arr, n);
    //Add print function

    return 0;
}