#include <iostream>

void merge(int arr1[], int size1, int arr2[], int size2, int arr3[],
           int &size3) {
    size3 = size1 + size2;
    int ind1 = 0;
    int ind2 = 0;
    int ind3 = 0;
    while (ind1 < size1 && ind2 < size2) {
        if (arr1[ind1] < arr2[ind2])
            arr3[ind3++] = arr1[ind1++];
        else
            arr3[ind3++] = arr2[ind2++];
    }

    while (ind1 < size1) {
        arr3[ind3++] = arr1[ind1++];
    }

    while (ind2 < size2) {
        arr3[ind3++] = arr2[ind2++];
    }
}

int main() {
    int arr1[1024], arr2[1024], arr3[2048];
    int n1, n2;
    std::cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }

    for (int i = 0; i < n2; i++) {
        std::cin >> arr2[i];
    }

    int n3;
    merge(arr1, n1, arr2, n2, arr3, n3);

    for (int i = 0; i < n3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}