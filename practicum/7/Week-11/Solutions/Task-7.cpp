#include <iostream>


void removeElement(int*& arr, int& size, int k) {
    int* newarr = new int[size - 1];
    for (int i = 0; i < k; i++) {
        newarr[i] = arr[i];
    }
    for (int i = k; i < size - 1; i++) {
        newarr[i] = arr[i + 1];
    }
    delete[] arr;
    arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = newarr[i];
    }
    size--;
    delete[] newarr;
}

int main()
{
    int arrSize;
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> arr[i];
    }
    removeElement(arr, arrSize, 2);
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}