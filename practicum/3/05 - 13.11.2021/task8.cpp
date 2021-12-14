#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < size / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
