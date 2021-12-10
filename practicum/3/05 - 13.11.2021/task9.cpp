#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int digitCount[10];
    for (int i = 0; i <= 9; i++) {
        digitCount[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int copy = arr[i];
        while (copy != 0) {
            digitCount[copy % 10]++;
            copy /= 10;
        }
    }

    for (int i = 0; i <= 9; i++) {
        std::cout << i << ": " << digitCount[i] << std::endl;
    }

    return 0;
}
