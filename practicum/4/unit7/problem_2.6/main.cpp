#include <iostream>

bool isLowercaseLetter(char c) {
	return c >= 'a' && c <= 'z';
}

void fillChars(const char str[], bool charOccurences[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (isLowercaseLetter(str[i])) {
			charOccurences[str[i] - 'a'] = true;
		}
	}
}

int main() {
	const int MAX_SIZE = 64;
	char s1[MAX_SIZE];
	char s2[MAX_SIZE];

	std::cin.getline(s1, MAX_SIZE);
	std::cin.getline(s2, MAX_SIZE);

	const int ALPHABET_SIZE = 26;

	bool s1Chars[ALPHABET_SIZE] = { false };
	bool s2Chars[ALPHABET_SIZE] = { false };
	fillChars(s1, s1Chars);
	fillChars(s2, s2Chars);

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (s1Chars[i] && !s2Chars[i]) {
			std::cout << (char)('a' + i) << ' ';
		}
	}

	return 0;
}