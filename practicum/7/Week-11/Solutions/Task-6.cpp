#include<iostream>
const int MAX_LEN = 1024;
const int MAX_WORDS = 1024;
int pCount = 0;

char* allocate(int n) {
	char* str = new char[n];
	pCount++;
	return str;
}
void deallocate(char* str) {
	delete[] str;
	pCount--;
}
void deallocate(char** lines, int n) {
	for (int i = 0; i < n; ++i)
		deallocate(lines[i]);
	delete[] lines;
	pCount--;
}

bool isCharacter(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
		return true;
	return false;
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

bool isInDictionary(char* word, char** dictionary, int size) {
	while ((size - 1) > 0) {
		if(!strcmp(word, dictionary[size - 1]))
			return true;

		size--;
	}

	return false;
}
void addToDictionary(char* word, char** dictionary, int& size) {
	if(size < MAX_LEN)
		if (!isInDictionary(word, dictionary, size)) {
			dictionary[size] = allocate(strlen(word) + 1);
			strcpy(dictionary[size], word);
			++size;
		}
}

void processSentence(char* sentence, char** dictionary, int& size) {
	char word[MAX_LEN];

	while (*sentence) {
		copyWord(word, sentence);
		addToDictionary(word, dictionary, size);
	}
}

char** getDictionary(char** sentences, int sentencesSize) {

	int dictionarySize = 0;
	char** dictionary = new char* [MAX_WORDS];
	pCount++;

	for (int i = 0; i < sentencesSize; ++i)
		processSentence(sentences[i], dictionary, dictionarySize);

	return dictionary;
}

void print(char** lines, int n) {
	for (int i = 0; i < n; ++i)
		std::cout << lines[i] << std::endl;
}

int main() {

	char buffer[MAX_LEN];
	
	int n;
	std::cin >> n;
	std::cin.ignore();

	char** sentences = new char* [n];
	pCount++;

	for (int i = 0; i < n; ++i) {
		std::cin.getline(buffer, MAX_LEN);
		sentences[i] = allocate(strlen(buffer) + 1);
		strcpy(sentences[i], buffer);
	}

	char** dictionary = getDictionary(sentences, n);
	print(dictionary, MAX_WORDS);

	deallocate(dictionary, MAX_WORDS);
	deallocate(sentences, n);

	std::cout << pCount << std::endl;

	return 0;
}