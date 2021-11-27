#include <iostream>

/// <summary>
/// SOLVED BY Mihaela Nikolova
/// </summary>
/// <returns>0</returns>
int main()
{
	const int MAX_LEN = 1000;
	int arr[MAX_LEN];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int day;
	int month;
	int sum = 0;
	int br = 0;
	std::cin >> day >> month;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < i + month; j++) {
			sum = sum + arr[j];
		}
		if (sum == day) {
			br++;
		}
		sum = 0;
	}
	std::cout << br;

}