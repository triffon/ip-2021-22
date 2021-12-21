#include <iostream>

const int MAX_SIZE = 128;

void findAndPrintMax(int* arr, int arrSize)
{
	int max = 1;
	for (int i = 0; i < arrSize - 1; i++) {
		int currLen = 1;
		while (arr[i] <= arr[i + 1]) {
			currLen++;
			i++;
		}
		if (currLen > max) {
			max = currLen;
		}
	}
	std::cout << max;

}
int main() {
	int arr[MAX_SIZE];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	findAndPrintMax(arr, n);

	return 0;
}