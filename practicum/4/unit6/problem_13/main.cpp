#include <iostream>

/*
	Задача 13
	Създайте функция, която приема 3 параметъра - масив от цели числа, размер на масива и число r. 
	Функцията да измества надясно всички елементи на масива с брой позиции, равен на r. 
	Последните елементи от масива да не се губят, а да отидат в началото. 
	Допуснете, че размерът на масива е най-много 256 елемента.
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

void rotate(int arr[], int n, int r) {
	int buf[256];

	for (int i = 0; i < n; i++) {
		buf[(i + r) % n] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = buf[i];
	}
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n, r;

	std::cin >> n >> r;
	readArr(arr, n);
	rotate(arr, n, r);
	printArr(arr, n);
	return 0;
}