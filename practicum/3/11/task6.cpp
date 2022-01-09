#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

char** sentenceToWords(const char* s, int& wordCount) {
	wordCount = 0;
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] >= 'a' && s[i] <= 'z' ||
			s[i] >= 'A' && s[i] <= 'Z' ||
			s[i] == '-') {
			continue;
		}

		wordCount++;
	}

	char** res = new char* [wordCount];

	int startInd = 0;
	int currInd = 0;
	for (int i = 0; i < wordCount; i++) {
		while (s[currInd] >= 'a' && s[currInd] <= 'z' ||
			s[currInd] >= 'A' && s[currInd] <= 'Z' ||
			s[currInd] == '-') {
			currInd++;
		}
		res[i] = new char[currInd - startInd + 1];
		strncpy(res[i], s + startInd, currInd - startInd);
		res[i][currInd - startInd] = '\0';
		startInd = currInd + 1;
		currInd++;
	}

	return res;
}

int main() {
	int n;
	std::cin >> n;

	char* sentence = new char[n + 1];

	std::cin.ignore();

	std::cin.getline(sentence, n + 1);

	int wordCount;
	char** words = sentenceToWords(sentence, wordCount);

	for (int i = 0; i < wordCount; i++) {
		bool flag = true;
		for (int j = 0; j < i && flag; j++) {
			if (strcmp(words[i], words[j]) == 0) {
				flag = false;
			}
		}
		if (flag) {
			int currentCount = 0;
			for (int j = 0; j < wordCount; j++) {
				if (strcmp(words[i], words[j]) == 0) {
					currentCount++;
				}
			}
			std::cout << words[i] << " -> " << currentCount << std::endl;
		}
	}
	

	for (int i = 0; i < wordCount; i++) {
		delete[] words[i];
	}
	delete[] words;
	delete[] sentence;
	return 0;
}