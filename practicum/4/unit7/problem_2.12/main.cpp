#include <iostream>

void replace(char str1[], char str2[], char str3[]) {
	for (int i = 0;; i++) {
		if (str1[i] == '\0') return;
		if (str1[i] == str2[0]) {
			bool shouldReplace = true;
			for (int j = 1;; j++) {
				if (str2[j] == '\0') break;
				if (str1[i + j] != str2[j]) {
					shouldReplace = false;
					break;
				}
			}
			if (shouldReplace) {
				for (int j = 0;; j++) {
					if (str2[j] == '\0') break;
					str1[i + j] = str3[j];
				}
			}
		}
	}
}

int main() {
	char str1[64];
	char str2[64];
	char str3[64];
	
	std::cin.getline(str1, 64);
	std::cin.getline(str2, 64);
	std::cin.getline(str3, 64);
	replace(str1, str2, str3);
	std::cout << str1 << std::endl;
}
