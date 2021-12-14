#include <iostream>

void insert(int arr[], int &size, int k, int pos) {
    size++;
    for (int i = size - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = k;
}

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int k, pos;
    std::cin >> k >> pos;

    insert(arr, n, k, pos);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}