#include <iostream>

int questionMarkOccurences(const char str[]) {
	int occurencesCount = 0;
	for (int i = 0;; i++) {
		switch (str[i]) {
			case '?': occurencesCount++; break;
			case '\0': return occurencesCount;
		}
	}
}

int main() {
	std::cout << questionMarkOccurences("??ASD???"); // 5 
}