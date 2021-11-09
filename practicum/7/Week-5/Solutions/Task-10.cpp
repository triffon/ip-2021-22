#include <iostream>

int main()
{
	int n;
	do {
		std::cin >> n;
	} while (n < 1 || n > 20);
	int arr[20];
	for (int i = 0; i < n; i++) {
		do {
			std::cout << "Enter value: ";
			std::cin >> arr[i];
			std::cout << std::endl;
		} while (arr[i] < 1 || arr[i] > 50);
	}
	int sum = 0;
	int product = 1;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		product *= arr[i];
	}
	std::cout << "Sum is equal to: " << sum;
	std::cout << "Product is equal to: " << product;
	return 0;
}