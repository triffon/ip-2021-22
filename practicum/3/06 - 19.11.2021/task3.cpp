#include <iostream>

void remove(int arr[], int &size, int pos) {
    size--;
    for (int i = pos; i < size; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int pos;
    std::cin >> pos;

    remove(arr, n, pos);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}