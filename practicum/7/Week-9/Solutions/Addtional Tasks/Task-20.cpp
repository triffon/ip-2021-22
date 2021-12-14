#include <iostream>

const int MAX_ELEMS = 128;

bool isPowOfTwo(int number) {
	int numberMinusOne = number - 1;
	int result = number & numberMinusOne;
	return result == 0;
}

int main() {
	char arr[MAX_ELEMS];
	bool resultArr[MAX_ELEMS];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		resultArr[i] = isPowOfTwo(arr[i]);
	}

	return 0;
}
