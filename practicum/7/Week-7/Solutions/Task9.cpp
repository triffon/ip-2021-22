#include<iostream>

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//task 9
bool is_pow_2(unsigned n) {
    return !(n & (n - 1));
}

void print_pows_2(unsigned arr[], int n) {
    for (int i = 0; i < n; ++i)
        if (is_pow_2(arr[i]))
            std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int main() {

    const unsigned MAX_ARRAY_LEN = 10;

    unsigned arr[MAX_ARRAY_LEN] = { 1, 2, 5, 7, 3, 14, 16, 5 };
    int n = 8;

    std::cout << "Powers of two: ";
    print_pows_2(arr, n);

	return 0;
}