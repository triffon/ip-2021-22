#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int hasDuplicate = false;

    for (int i = 0; i < size && !hasDuplicate; i++) {
        for (int j = i + 1; j < size && !hasDuplicate; j++) {
            if (arr[i] == arr[j])
                hasDuplicate = true;
        }
    }

    std::cout << std::boolalpha << hasDuplicate << std::endl;

    return 0;
}