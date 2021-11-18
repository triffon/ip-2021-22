#include <iostream>

/*
	Задача 9
	Създайте функция, която, по дадени 2 масива във възходящ ред, слива масивите в един, който е също сортиран във възходящ ред.
*/

void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void merge(int arr1[], int n1, int arr2[], int n2, int dst[]) {
	int arr1Idx = 0;
	int arr2Idx = 0;
	int dstIdx = 0;
	while (arr1Idx < n1 && arr2Idx < n2) {
		if (arr1[arr1Idx] <= arr2[arr2Idx]) {
			dst[dstIdx++] = arr1[arr1Idx++];
		} else {
			dst[dstIdx++] = arr2[arr2Idx++];
		}
	}

	while (arr1Idx < n1) {
		dst[dstIdx++] = arr1[arr1Idx++];
	}

	while (arr2Idx < n2) {
		dst[dstIdx++] = arr2[arr2Idx++];
	}
}

int main() {
	const int MAX_ARRAY_SIZE = 256;
	int arr1[MAX_ARRAY_SIZE/2], arr2[MAX_ARRAY_SIZE/2], mergedArr[MAX_ARRAY_SIZE];
	int n1, n2;

	std::cin >> n1;
	readArr(arr1, n1);
	std::cin >> n2;
	readArr(arr2, n2);

	merge(arr1, n1, arr2, n2, mergedArr);
	printArr(mergedArr, n1+n2);

	return 0;
}