#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int maxSum = arr[0] + arr[1];

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] > maxSum)
                maxSum = arr[i] + arr[j];
        }
    }

    std::cout << maxSum << std::endl;

    return 0;
}