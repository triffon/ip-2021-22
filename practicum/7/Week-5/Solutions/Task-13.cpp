#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int a, b;
	std::cin >> a >> b;
	int arr[256];
	if (n > 256) {
		std::cout << "Not enough memory allocated!";
	}
	else {
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		bool allAreContained = true;
		for (int i = a; i <= b; i++) {
			bool currentIsContained = false;
			for (int j = 0; j < n; j++) {
				if (arr[j] == i) {
					currentIsContained = true;
					break;
				}
			}
			if (!currentIsContained) {
				allAreContained = false;
				break;
			}
		}
		std::cout << allAreContained;
	}
	return 0;
}