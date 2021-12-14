#include <iostream>

void insert(int arr[], int &size, int k, int pos) {
    size++;
    for (int i = size - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = k;
}

void insertSorted(int arr[], int &size, int num) {
    int pos = 0;
    while (pos <= size && arr[pos++] <= num) {}
    // Или разписано подробно
    // while (pos <= size && arr[pos] <= num) {
    //     pos++;
    // }

    insert(arr, size, num, pos - 1);
}

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int num;
    std::cin >> num;

    insertSorted(arr, n, num);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}