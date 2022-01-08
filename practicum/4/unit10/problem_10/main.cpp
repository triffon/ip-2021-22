#include <iostream>
#include <cstring>

bool isSymmetric(char str[], int size, int startIdx) {
	if (startIdx >= size / 2) return true;
	if (str[startIdx] != str[size - startIdx - 1]) return false;
	return isSymmetric(str, size, startIdx + 1);
}
int main() {
	char buf[64];
	std::cin.getline(buf, 64);
	std::cout << std::boolalpha << isSymmetric(buf, strlen(buf), 0);
	return 0;
}