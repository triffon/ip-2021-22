#include <iostream>

/*
	Задача 5
	Създайте функция, която по даден сортиран масив a и цяло число x 
	връща индекса на елемента х в масива а и -1, ако х не се среща в масива. Използвайте алгоритъма 	двоично търсене.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int binarySearch(int arr[], int n, int x) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	return -1;
}
int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n, x;

	std::cin >> n >> x;
	readArr(arr, n);
	std::cout << binarySearch(arr, n, x);
	
	return 0;
}