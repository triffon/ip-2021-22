#include<iostream>

const unsigned MAX_ARRAY_LEN = 10;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//task 8
void shift_right_from(int arr[], int& n, int pos) {
    for (int i = n; i > pos; --i)
        arr[i] = arr[i - 1];

    n++;
}

void insert_at(int arr[], int pos, int elem) {
    if (pos >= MAX_ARRAY_LEN || pos < 0)
        std::cout << pos << " is out of bounds!\n";

    arr[pos] = elem;
}

void remove_at(int arr[], int& n, int pos) {
    if (pos >= MAX_ARRAY_LEN || pos < 0)
        std::cout << pos << " is out of bounds!\n";

    for (pos; pos < n; ++pos)
        arr[pos] = arr[pos + 1];

    n--;
}

int main() {
    int n = 5;
    int arr[MAX_ARRAY_LEN] = { 1, 2, 7, 5, 3 };

    std::cout << "Before shift: ";
    print_arr(arr, n);

    std::cout << "After shift: ";
    int pos = 2;
    shift_right_from(arr, n, pos);
    print_arr(arr, n);

    std::cout << "After insert: ";
    insert_at(arr, pos, 1024);
    print_arr(arr, n);

    std::cout << "After removal: ";
    remove_at(arr, n, pos);
    print_arr(arr, n);

	return 0;
}