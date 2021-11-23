#include<iostream>

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//task6
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int min_index = 0;

    for (int i = 0; i < n - 1; ++i) {
        min_index = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void insert_at_sorted(int arr[], int n, int elem) {
    //Същото като shift_right и insert, само че не местим елементите надясно
    //докато стигнем конкретна позиция, а докато не станат тези елементи,
    //по-малки или равни на този, който искаме да вкараме
    int pos = n;

    while (pos > 0 && arr[pos - 1] > elem) {
        arr[pos] = arr[pos - 1];
        --pos;
    }
    arr[pos] = elem;
}

void insertion_sort(int arr[], int n) {
    //Няма смисъл да започваме от i = 0, защото insert-ваме arr[0]
    for (int i = 1; i < n; ++i)
        insert_at_sorted(arr, i, arr[i]);
}

int main() {

    const unsigned MAX_ARRAY_LEN = 10;

    //task 7
    int arr[MAX_ARRAY_LEN] = { 1, 16, -3, 8, 9 };
    int len = 5;

    std::cout << "unsorted: ";
    print_arr(arr, len);
    //bubble_sort(arr, len);
    //selection_sort(arr, len);
    insertion_sort(arr, len);

    std::cout << "sorted: ";
    print_arr(arr, len);

	return 0;
}