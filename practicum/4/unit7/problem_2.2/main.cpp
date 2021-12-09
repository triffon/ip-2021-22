#include <iostream>

char toUpperCase(char c) {
	return (c >= 'a' && c <= 'z' ? c + 'A' - 'a' : c);
}

void toUpperCase(char str[], char result[]) {
	for (int i = 0;; i++) {
		result[i] = toUpperCase(str[i]);
		if (str[i] == '\0') {
			return;
		}
	}
}

int main() {
	char str[] = "testSTRING1234509";
	char result[64];
	toUpperCase(str, result);
	std::cout << result;
}