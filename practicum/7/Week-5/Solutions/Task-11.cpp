#include <iostream>

int main()
{
	int n;
	do {
		std::cout << "Enter number between 1 and 1000: ";
		std::cin >> n;
	} while (n < 1 || n > 1000);
	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		std::cout << "arr[i]= ";
		std::cin >> arr[i];
	}
	int minNumber = INT_MAX;
	int maxNumber = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxNumber) {
			maxNumber = arr[i];
		}
		if (arr[i] < minNumber) {
			minNumber = arr[i];
		}
	}
	std::cout << "Min: " << minNumber;
	std::cout << "Max: " << maxNumber;

	return 0;
}