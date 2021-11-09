#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int arr[128];
	if (n > 128) {
		std::cout << "Entered too big count";
	}
	else {
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			bool isPrime = true;
			for (int j = 1; j < arr[i]; j++) {
				if (arr[i] % j == 0 && j != 1) {
					isPrime = false;
					break;
				}
			}
			if (isPrime && arr[i] > 1) {
				std::cout << arr[i];
			}
		}
	}
	return 0;
}