#include <iostream>

void readArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

bool contains(int arr[], int size, int startIdx, int x) {
	if (startIdx >= size) return false;
	if (arr[startIdx] == x) return true;
	return contains(arr, size, startIdx + 1, x);
}

int main() {
	int arr[64];
	int size, x;
	std::cin >> size >> x;
	readArr(arr, size);
	std::cout << std::boolalpha << contains(arr, size, 0, x);
	return 0;
}