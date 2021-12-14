#include <iostream>

int main() {
    int arr[1024];
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int max = 0;
    int curr = 1;
    int last = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] != last) {
            if (curr > max)
                max = curr;

            curr = 0;
        }
        curr++;
        last = arr[i];
    }
    if (curr > max)
        max = curr;

    std::cout << max << std::endl;

    return 0;
}
