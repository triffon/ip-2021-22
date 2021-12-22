#include <iostream>
const int MAX_LEN = 1024;

void deallocate(char** words, int n) {
	for (int i = 0; i < n; ++i)
		delete[] words[i];
	delete[] words;
}

bool isCharacter(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
		return true;
	return false;
}

int countWords(char* str) {
	int count = 1;

	while (*str) {
		if (!isCharacter(*str))
			count++;

		++str;
	}

	return count;
}

int currentWordSize(char* str) {
	int size = 0;

	while (isCharacter(*str)) {
		++size;
		++str;
	}

	return size;
}

void copyWord(char* dest, char*& src) {
	while (*src && isCharacter(*src)) {
		*dest = *src;
		++dest;
		++src;
	}

	*dest = '\0';

	while (*src && !isCharacter(*src))
		++src;
}

char** getWords(char* str, int size) {
	char** words = new char* [size];

	for (int i = 0; i < size; ++i) {
		words[i] = new char[currentWordSize(str) + 1];
		copyWord(words[i], str);
	}

	return words;
}

void print(char** words, int size) {
	for (int i = 0; i < size; ++i)
		std::cout << words[i] << std::endl;
}

int main() {

	char buffer[MAX_LEN];
	std::cin.getline(buffer, MAX_LEN);

	int size = countWords(buffer);
	char** words = getWords(buffer, size);
	
	print(words, size);

	deallocate(words, size);
	return 0;
}