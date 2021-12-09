#include <iostream>

int contains(const char s1[], const char s2[]) {
	int occurencesCount = 0;
	for (int i = 0;; i++) {
		if (s1[i] == '\0') return occurencesCount;
		if (s1[i] == s2[0]) {
			for (int j = 1;; j++) {
				if (s2[j] == '\0') {
					occurencesCount++;
					break;
				}
				if (s1[i + j] != s2[j]) {
					break;
				}
			}
		}
	}
}

int main() {
	char s1[64];
	char s2[64];
	std::cin.getline(s1, 64);
	std::cin.getline(s2, 64);
	std::cout << contains(s1, s2);
}