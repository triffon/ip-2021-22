#include <iostream>

/*
	Задача 11
	Създайте функция, която приема 3 параметъра - масив, размер на масива и индекс. 
	Функцията да премахне елементът от масива с индекс равен на подадения индекс.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void removeElement(int arr[], int n, int idx) {
	for (int i = idx; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n, idx;

	std::cin >> n >> idx;
	readArr(arr, n);
	removeElement(arr, n, idx);
	printArr(arr, n - 1);
	return 0;
}