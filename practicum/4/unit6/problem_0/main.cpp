#include <iostream>

/*
	Задача 0
	Създайте функции, която прочитат и извеждав масив от цели числа от/в конзолата. 
	Създайте функция, която извежда масив от цели числа в обратен ред.
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

void printReversed(int arr[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}