#include <iostream>

/*
	Задача 6
	Създайте функция, която проверява дали даден масив е сортиран във възходящ ред.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

bool isSorted(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(arr, n);
	std::cout << (isSorted(arr, n) ? "The array is sorted" : "The array is not sorted");
	
	return 0;
}