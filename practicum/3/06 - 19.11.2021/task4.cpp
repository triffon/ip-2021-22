#include <iostream>

bool sorted(int arr[], int size) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1])
            decreasing = false;
        
        if (arr[i] < arr[i - 1])
            increasing = false;
    }

    return increasing || decreasing;
}

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << std::boolalpha << sorted(arr, n) << std::endl;
    return 0;
}