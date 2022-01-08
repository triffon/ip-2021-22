#include <iostream>

const int TEXT_SIZE = 2048;

/// <summary>
///					CHECK THE WHOLE SOLUTION FOR MISTAKES AND SEND ME QUESTIONS ABOUT EVERYTHING YOU FIND
/// </summary>


int countWords(char* text) {
	int textLen = strlen(text);
	int count = 1;
	for (int i = 0; i < textLen; i++)
	{
		if (text[i] == ' ') {
			++count;
		}
	}
	return count;
}

char** mapWords(char* text, int& textWordsCount)
{
	int textLength = strlen(text);
	textWordsCount = countWords(text);
	char** words = new char* [textWordsCount];
	int wordsRowIndex = 0;
	char tempWord[256];
	int tempWordIndex = 0;
	for (int i = 0; i < textLength; i++)
	{
		if (text[i+1] == '\0' || text[i] == ' ') {
			int wordSize = strlen(tempWord) + 1;
			words[wordsRowIndex] = new char[wordSize];
			strcpy_s(words[wordsRowIndex], wordSize, tempWord);
			wordsRowIndex++;
			strcpy_s(tempWord, wordSize, "\0"); //reset word to ""
			tempWordIndex = 0;  //reset index
		}
		else if (text[i] != ' ') {
			tempWord[tempWordIndex++] = text[i];
			tempWord[tempWordIndex] = '\0';
		}
	}
	return words;
}

//Check this for mistakes!
int findMaxConsecutiveWordsCount(char** textWords, int textWordsCount, char** sentenceWords, int sentenceWordsCount)
{
	int currConsecCount = 0, maxConsecCount = 0;
	int currIndexInSentence = 0;
	for (int i = 0; i < sentenceWordsCount; i++)
	{
		currIndexInSentence = i;
		for (int j = 0; j < textWordsCount; j++)
		{
			if (strcmp(textWords[j], sentenceWords[currIndexInSentence]) == 0) {
				currConsecCount++;
				if (currIndexInSentence != sentenceWordsCount - 1) {
					currIndexInSentence++;
				}
				else {
					if (currConsecCount > maxConsecCount) {
						maxConsecCount = currConsecCount;
					}
				}
			}
			else {
				if (currConsecCount > maxConsecCount) {
					maxConsecCount = currConsecCount;
				}
				currConsecCount = 0;
				currIndexInSentence = i;
				j -= currConsecCount;
			}
		}
	}
	return maxConsecCount;
}

double findSameWordsPercent(char** textWords, int textWordsCount, char** sentenceWords, int sentenceWordsCount)
{
	int countOfSameWords = 0;
	for (int i = 0; i < sentenceWordsCount; i++)
	{
		for (int j = 0; j < textWordsCount; j++)
		{
			if (strcmp(sentenceWords[i], textWords[j]) == 0)
			{
				countOfSameWords++;
				break;
			}
		}
	}
	return (countOfSameWords / (double)textWordsCount) * 100;
}

void fillBoolArrWithFalse(bool* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = false;
	}
}
 
char* myItoa(int num, char* buffer, int base) {
    int currIndex = 0;
 
    if (num == 0) {
        buffer[currIndex++] = '0';
        buffer[currIndex] = '\0';
        return buffer;
    }
 
    int digitsCount = 0;
 
    if (num < 0) {
        if (base == 10) {
            digitsCount++;
            buffer[currIndex++] = '-';
            num *= -1;
        }
        //add functionality for other bases HW
    }
 
    digitsCount += (int)floor(log(num) / log(base)) + 1;
 
    // Go through the digits one by one from left to right
    while (currIndex < digitsCount) {
        // Get the base value. For example, 10^2 = 1000, for the third digit
        int baseVal = (int) pow(base, digitsCount-1-currIndex);
 
        // Get the numerical value
        int numVal = num / baseVal;
 
        char value = numVal + '0';
        buffer[currIndex++] = value;
 
        num -= baseVal * numVal;
    }
    buffer[currIndex] = '\0';
    return buffer;
}

char** createWordsHistogram(char** textWords, int textWordsCount, int& histoSize)
{
	bool* visited = new bool[textWordsCount];
	char** histo = new char* [textWordsCount];
	int histoIndex = 0;
	fillBoolArrWithFalse(visited, textWordsCount);

	int counter = 0;

	for (int i = 0; i < textWordsCount; i++)
	{
		if (visited[i] == false)
		{
			counter = 0;
			for (int j = i; j < textWordsCount; j++)
			{
				if (strcmp(textWords[i], textWords[j]) == 0) {
					counter++;
					visited[j] = true;
				}
			}
			histoSize++;
			char counterStr[10];
			char* tempStrPtr = myItoa(counter,counterStr, 10);
			int numberLen = strlen(tempStrPtr);
			int size = strlen(textWords[i]) + numberLen + 4; // 4 is = (size of " - " + 1 for the '\0')
			histo[histoIndex] = new char[size];
			strcpy_s(histo[histoIndex], size, textWords[i]);
			strcat_s(histo[histoIndex], size, " - ");
			strcat_s(histo[histoIndex], size, tempStrPtr);
			histoIndex++;
		}
	}
	delete[] visited;
	return histo;
}

void printMatrix(char** matrix, int rowsCount) {

	for (int i = 0; i < rowsCount; i++)
	{
		std::cout << matrix[i] << ' ';
	}
}

void freeMatrix(char** matrix, int rowsCount)
{
	for (int i = 0; i < rowsCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	char* text = new char[TEXT_SIZE + 1]; // we need one more for the '\0'
	std::cout << "Enter text: ";
	std::cin.getline(text, 2048, '\n');

	std::cin.clear();

	int sentenceSize;
	std::cout << "Enter sentence length: ";
	std::cin >> sentenceSize;   //HW: validate for positivity
	std::cout << "Enter sentence: ";
	std::cin.ignore();
	char* sentence = new char[sentenceSize + 1];
	std::cin.getline(sentence, sentenceSize + 1, '\n');

	int textWordsCount = 0, sentenceWordsCount = 0;
	char** textWords = mapWords(text, textWordsCount);
	char** sentenceWords = mapWords(sentence, sentenceWordsCount);


	std::cout << findSameWordsPercent(textWords, textWordsCount, sentenceWords, sentenceWordsCount);

	int histoSize = 0;
	char** histo = createWordsHistogram(textWords, textWordsCount, histoSize);
	printMatrix(histo, histoSize);
	
	
	freeMatrix(histo, histoSize);
	freeMatrix(textWords, textWordsCount);
	freeMatrix(sentenceWords, sentenceWordsCount);
	delete[] text;
	delete[] sentence;

	return 0;
}