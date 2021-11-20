#include <iostream>

/*
	Задача 8
	Създайте функция, която сортира масив във възходящ ред.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int x = arr[j];
				arr[j] = arr[i];
				arr[i] = x;
			}
		}
	}
}

void selectionSort(int arr[], int n) {
	int sortedArrSize = 0;
	for (int sortedArrSize = 0; sortedArrSize < n; sortedArrSize++) {
		int currentMinIndex = sortedArrSize;
		for (int i = sortedArrSize; i < n; i++) {
			if (arr[i] < arr[currentMinIndex]) {
				currentMinIndex = i;
			}
		}
		int x = arr[currentMinIndex];
		arr[currentMinIndex] = arr[sortedArrSize];
		arr[sortedArrSize] = x;
	}
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(arr, n);
	selectionSort(arr, n);
	printArr(arr, n);
	return 0;
}