#include <iostream>


void readArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

void setMinMax(int arr[], int size, int *min, int *max) {
	*min = arr[0];
	*max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > *max) {
			*max = arr[i];
		}
		if (arr[i] < *min) {
			*min = arr[i];
		}
	}
}

int main() {
	int arr[64];
	int n;
	std::cin >> n;
	readArr(arr, n);

	int min, max;
	setMinMax(arr, n, &min, &max);

	std::cout << "Min = " << min << ", max = " << max;
	return 0;
}