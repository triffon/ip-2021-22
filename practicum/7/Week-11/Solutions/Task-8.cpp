#include <iostream>


bool equal(int* arr1, int* arr2, int arr1Size, int arr2Size) {
	bool contains = false;
	int temp = 0;

	for (int i = 0; i < arr1Size; i++) {
		temp = arr1[i];
		contains = false;
		for (int j = 0; j < arr2Size; j++) {
			if (arr2[j] == temp) {
				contains = true;
			}
		}
		if (!contains) {
			return false;
		}
	}
}

int main() {
	/*
	* do some input here
	*/
	bool areEqual = equal(arr1, arr2, arr1Size, arr2Size);
	if (areEqual) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}
	return 0;
}