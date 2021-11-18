#include <iostream>

/*
	Задача 7
	Създайте функция, която проверява дали даден масив от цели числа има уникални елементи.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

bool hasUniqueElements(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) return false;
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
	std::cout << (hasUniqueElements(arr, n) ? "The array has unique elements" : "The array does not have unique elements");
	
	return 0;
}