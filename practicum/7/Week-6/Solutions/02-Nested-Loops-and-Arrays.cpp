#include<iostream>
const unsigned MAX_LEN = 1024;

int main() {

	int n;
	std::cin >> n;

	int arr[MAX_LEN];

	int sum = 0;

	int arr_len = 0;

	while (n) {

		std::cin >> arr_len;

		for (int i = 0; i < arr_len; ++i) {
			std::cin >> arr[i];
		}
		
		int min = arr[0];
		int max = arr[0];

		for (int i = 0; i < arr_len; ++i) {
			if (arr[i] > max)
				max = arr[i];

			if (arr[i] < min)
				min = arr[i];
		}

		sum += (max - min);
		std::cout << max - min << ", sum: " << sum << std::endl;

		--n;
	}
	return 0;
}