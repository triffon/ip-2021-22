#include <iostream>

bool isSmallLetter(char c) {
	return c >= 'a' && c <= 'z';
}

bool isCapitalLetter(char c) {
	return c >= 'A' && c <= 'Z';
}

void extractSmallLetters(char* str, int n, char* result) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (isSmallLetter(str[i])) {
			result[index] = str[i];
			index++;
		}
	}
	result[index] = '\0';
}

void extractCapitalLetters(char* str, int n, char* result) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (isCapitalLetter(str[i])) {
			result[index] = str[i];
			index++;
		}
	}
	result[index] = '\0';
}

bool checkEquality(char* str, int n) {
	char* smalls = new char[strlen(str) + 1];
	extractSmallLetters(str, n, smalls);

	char* capitals = new char[strlen(str) + 1];
	extractCapitalLetters(str, n, capitals);

	if (strlen(smalls) != strlen(capitals)) {
		delete[] smalls;
		delete[] capitals;
		return false;
	}

	for (int i = 0; i < strlen(smalls); i++) {
		if (smalls[i] - 32 != capitals[i]) {
			delete[] smalls;
			delete[] capitals;
			return false;
		}
	}
	delete[] smalls;
	delete[] capitals;
	return true;
}

int main() {
	char* textString = new char[256];
	std::cin.getline(textString, 256);
	std::cout << std::boolalpha << checkEquality(textString, strlen(textString));
	delete[] textString;
	return 0;
}