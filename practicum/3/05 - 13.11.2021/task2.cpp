#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}