#include <iostream>

/*
	Задача 4
	Създайте функция, която по даден масив a и цяло число x връща колко пъти числото 
	се съдържа в масива (последователно търсене).
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int occurencesCount(int arr[], int size, int num) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			count++;
		}
	}
	return count;
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n, x;

	std::cin >> n >> x;
	readArr(arr, n);
	std::cout << occurencesCount(arr, n, x);
	
	return 0;
}