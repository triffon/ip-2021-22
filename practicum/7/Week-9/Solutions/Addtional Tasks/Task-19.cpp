#include <iostream>

bool isSmallLetter(char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}

bool isCapitalLetter(char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
		
}

int main() {
	char arr[100];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int smallsCounter = 0;
	int bigsCounter = 0;
	for (int i = 0; i < n; i++) {
		if (isSmallLetter(arr[i])) {
			smallsCounter++;
		}
		if (isCapitalLetter(arr[i])) {
			bigsCounter++;
		}
	}
	std::cout << smallsCounter << " " << bigsCounter;

	return 0;
}