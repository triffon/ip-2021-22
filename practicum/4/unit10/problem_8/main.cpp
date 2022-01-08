#include <iostream>

int occurrencesCount(char str[], int startIdx, char c) {
	if (str[startIdx] == '\0') {
		return 0;
	}
	if (str[startIdx] == c) {
		return 1 + occurrencesCount(str, startIdx + 1, c);
	}
	return occurrencesCount(str, startIdx + 1, c);
}

int main() {
	char buf[64];
	std::cin.getline(buf, 64);
	char c;
	std::cin >> c;
	std::cout << buf << " contains " << c << " " << occurrencesCount(buf, 0, c) << " times\n";
	return 0;
}