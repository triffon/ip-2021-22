#include <iostream>

bool isSymmetrical(const char str[]) {
	int n = strlen(str);
	for (int i = 0; i <= n / 2; i++) {
		if (str[i] != str[n - i -1]) return false;
	}
	return true;
}

int main() {

	std::cout << std::boolalpha << isSymmetrical("asdf") << '\n';
	std::cout << isSymmetrical("asdfdsa") << '\n';
	std::cout << isSymmetrical("a") << '\n';
	std::cout << isSymmetrical("") << '\n';
}