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

int count(char** words, int wordCount, char* word) {
	int currentCount = 0;

	for (int j = 0; j < wordCount; j++) {
		if (strcmp(word, words[j]) == 0) {
			currentCount++;
		}
	}

	return currentCount;
}

int main() {
	int n;
	std::cin >> n;

	char* sentence = new char[n + 1];

	std::cin.ignore();

	std::cin.getline(sentence, n + 1);

	int wordCount;
	char** words = sentenceToWords(sentence, wordCount);
	char* mostCommonWord = nullptr;
	int maxCount = -1;

	for (int i = 0; i < wordCount; i++) {
		int currentCount = count(words, wordCount, words[i]);
		if (maxCount < currentCount) {
			maxCount = currentCount;
			mostCommonWord = words[i];
		}
	}

	std::cout << maxCount << "\"" << mostCommonWord << "\"" << std::endl;

	char* newSentence = new char[n + 1 - strlen(mostCommonWord) * maxCount - maxCount];
	int newInd = 0;
	for (int i = 0; i < wordCount; i++) {
		if (strcmp(words[i], mostCommonWord) != 0) {
			for (int j = 0; j < strlen(words[i]); j++) {
				newSentence[newInd++] = words[i][j];
			}
			
			newSentence[newInd++] = ' ';
		}
	}
	newSentence[newInd - 1] = '\0';

	std::cout << "\"" << newSentence << "\"" << std::endl;

	for (int i = 0; i < wordCount; i++) {
		delete[] words[i];
	}
	delete[] words;
	delete[] sentence;
	return 0;
}
