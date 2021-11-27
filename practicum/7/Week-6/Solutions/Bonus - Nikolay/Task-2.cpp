#include <iostream>

int main()
{
    // This is not a final solution just an idea.
    int arr[1024];
    int size = 0;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) cnt++;
        }
    }
    std::cout << (cnt % 2 == 0) ? "YES" : "NO";

}