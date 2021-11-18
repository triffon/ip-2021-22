#include <iostream>

/*
	Задача 10
	Създайте функция, която приема масив от цели числа и размер на масива и
	връща дължината на най-дългата растяща последователност елементи на масива.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int longestSequenceLength(int arr[], int n) {
	int maxLength = 0;
	for (int i = 0; i < n;) {
		int currentLength = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				currentLength++;
				continue;
			}
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
			i += j;
			break;
		}
		
	}
	return maxLength;
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(arr, n);
	std::cout << longestSequenceLength(arr, n);
	return 0;
}