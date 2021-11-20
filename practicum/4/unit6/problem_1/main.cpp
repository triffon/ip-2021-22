#include <iostream>

/*
	Задача 1
	Създайте програма, която прочита цяло число n и n цели числа от конзолата. 
	Програмата да изведе сумата на нечетните числа.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int sumOfOddNumbers(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			sum += arr[i];
		}
	}
	return sum;
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr[MAX_ARRAY_SIZE];
	int n;

	std::cin >> n;
	readArr(arr, n);
	std::cout << sumOfOddNumbers(arr, n);
	
	return 0;
}