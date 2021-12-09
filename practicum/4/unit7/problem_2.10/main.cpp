#include <iostream>

int min(int n1, int n2) {
	return n1 < n2 ? n1 : n2;
}

int hamming(const char s1[], const char s2[]) {
	int hamming = 0;

	for (int i = 0;; i++) {
		if (s1[i] == '\0' || s2[i] == '\0') {
			return hamming;
		}
		if (s1[i] != s2[i]) hamming++;
	}
	return hamming;
}

int main() {
	char s1[64];
	char s2[64];
	std::cin.getline(s1, 64);
	std::cin.getline(s2, 64);
	std::cout << hamming(s1, s2);
}