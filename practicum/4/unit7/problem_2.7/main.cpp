#include <iostream>

bool isUppercaseLetter(char c) {
	return c >= 'A' && c <= 'Z';
}

bool isLowercaseLetter(char c) {
	return c >= 'a' && c <= 'z';
}


bool hasUniqueLetters(char str[]) {
	// letters[i] says if the letter with ASCII code 'a'+i has already been found in str
	bool letters[26] = { 0 }; // 26 is the count of lower-case latin characters in the ASCII table
	
	for (int i = 0;; i++) {
		if (str[i] == '\0') return true;
		if (isLowercaseLetter(str[i])) {
			if (letters[str[i] - 'a']) return false;
			letters[str[i] - 'a'] = true;
		} else if (isUppercaseLetter(str[i])) {
			if (letters[str[i] - 'A']) return false;
			letters[str[i] - 'A'] = true;
		}
	}

}

int main() {
	char s[64];
	std::cin.getline(s, 64);
	std::cout << std::boolalpha << hasUniqueLetters(s);
}