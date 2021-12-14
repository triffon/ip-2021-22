#include <iostream>
#include <cstring>

// Функцията допуска, че в n1 и n2 единствените символи са '1', '2', ..., '9'
int strToInt(const char str[]) {
	int number = 0;
	int multiplier = 1;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		const int digit = str[i] - '0';
		number += digit * multiplier;
		multiplier *= 10;
	}
	return number;
}

int strintcmp(const char n1[], const char n2[]) {
	int n1Int = strToInt(n1);
	int n2Int = strToInt(n2);
	return n1Int >= n2Int ? n1Int : n2Int;
}

int main() {
	char s1[64];
	char s2[64];
	std::cin.getline(s1, 64);
	std::cin.getline(s2, 64);
	std::cout << strintcmp(s1, s2);
}