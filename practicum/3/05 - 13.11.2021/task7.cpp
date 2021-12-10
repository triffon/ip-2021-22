#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    bool increasing = true;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            increasing = false;
            break;
        }
    }

    std::cout << std::boolalpha << increasing << std::endl;

    return 0;
}
