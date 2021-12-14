#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    bool hasK = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == k) {
            hasK = true;
            break;
        }
    }

    std::cout << std::boolalpha << hasK << std::endl;

    return 0;
}