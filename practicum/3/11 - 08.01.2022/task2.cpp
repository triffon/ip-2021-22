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
	int n, m;
	std::cin >> n >> m;

	char* sentence = new char[n + 1];
	char* word = new char[m + 1];

	std::cin.ignore();

	std::cin.getline(sentence, n + 1);
	std::cin.getline(word, m + 1);

	for (int i = 0; i < m / 2; i++) {
		char tmp = word[i];
		word[i] = word[m - i - 1];
		word[m - i - 1] = tmp;
	}

	int wordCount;
	char** words = sentenceToWords(sentence, wordCount);

	int count = 0;
	for (int i = 0; i < wordCount; i++) {
		if (strcmp(word, words[i]) == 0) {
			count++;
		}
	}

	std::cout << count << std::endl;
	
	delete[] word;
	delete[] sentence;

	for (int i = 0; i < wordCount; i++) {
		delete[] words[i];
	}
	delete[] words;
	return 0;
}