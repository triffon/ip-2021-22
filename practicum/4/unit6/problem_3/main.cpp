#include <iostream>

/*
	Задача 3
	Създайте функция, която извежда най-голямото цяло число от масив с размер n.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int max(int arr[], int n) {
	int currentMax = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > currentMax) {
			currentMax = arr[i];
		}
	}
	return currentMax;
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(arr, n);
	std::cout << max(arr, n);
	
	return 0;
}