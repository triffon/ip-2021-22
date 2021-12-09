#include <iostream>

void printDiamond(const char str[]) {
	int strlen;
	for (int i = 0;; i++) {
		if (str[i] == '\0') { 
			strlen = i;
			break;
		}
		for (int j = 0; j <= i; j++) {
			std::cout << str[j];
		}
		std::cout << '\n';
	}

	for (int i = 1; i < strlen; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << " ";
		}
		for (int j = i; j < strlen; j++) {
			std::cout << str[j];
		}
		std::cout << '\n';
	}
}

int main() {
	printDiamond("STRING");
}