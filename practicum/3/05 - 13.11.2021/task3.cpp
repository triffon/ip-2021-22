#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int sum = 0;

    for (int i = 1; i < size; i++) {
        sum += arr[i];
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}