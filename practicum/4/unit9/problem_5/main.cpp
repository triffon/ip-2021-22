#include <iostream>

/*
	Създайте функция, която приема масив от цели числа. 
	Функцията да върне указател към първия отрицателен елемент на масива или `nullptr`, ако такъв елемент не съществува.
*/

void readArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

int* firstNegative(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			return &arr[i];
		}
	}
	return nullptr;
}

int main() {
	int arr[64];
	int n; 
	std::cin >> n;
	readArr(arr, n);
	int *firstNegativePtr = firstNegative(arr, n);
	if (firstNegativePtr) {
		std::cout << "The first negative number in the array is " << *firstNegativePtr << " at address " << firstNegativePtr;
	} else {
		std::cout << "The array does not have negative numbers";
	}
	return 0;
}