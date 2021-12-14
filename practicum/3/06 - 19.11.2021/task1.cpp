#include <iostream>

void printPairsWithSumK(int arr[], int size, int k) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] + arr[j] == k) {
                std::cout << arr[i] << " " << arr[j] << std::endl; 
            }
        }
    }
}

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    printPairsWithSumK(arr, n, k);

    return 0;
}