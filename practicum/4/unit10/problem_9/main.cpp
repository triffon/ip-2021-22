#include <iostream>

void readArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

bool isIncreasingSequence(int arr[], int size, int startIdx) {
	if (startIdx >= size - 1) return true;
	return arr[startIdx] < arr[startIdx + 1] && isIncreasingSequence(arr, size, startIdx + 1);
}

int main() {
	int arr[64];
	int size;
	std::cin >> size;
	readArr(arr, size);
	std::cout << std::boolalpha << isIncreasingSequence(arr, size, 0);
	return 0;
}