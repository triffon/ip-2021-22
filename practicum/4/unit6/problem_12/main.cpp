#include <iostream>

/*
	Задача 12
	Създайте функция, която приема 4 параметъра - масив от цели числа, размер на масива, индекс и число. 
	Функцията да добави даденото число на дадения индекс в масива. 
	Функцията допуска, че в масива има достатъчно място за добавяне на още 1 елемент.
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

void insert(int arr[], int n, int idx, int number) {
	for (int i = n; i > idx; i--) {
		arr[i] = arr[i - 1];
	}
	arr[idx] = number;
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n, idx, numToInsert;

	std::cin >> n >> idx >> numToInsert;
	readArr(arr, n);
	insert(arr, n, idx, numToInsert);
	printArr(arr, n + 1);
	return 0;
}