#include <iostream>

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int* extractInts(char* str, int size, int& intsArrSize)
{
	int* numbers = new int[100];
	for (int i = 0; i < 100; i++)
	{
		numbers[i] = 0;
	}

	int numbersIndex = 0;
	int sentenceIndex = 0;
	bool isNegative = false;

	while (sentenceIndex < size)
	{
		if (str[sentenceIndex] == '-')
		{
			isNegative = true;
		}

		if (isDigit(str[sentenceIndex]))
		{
			numbers[numbersIndex] = numbers[numbersIndex] * 10;
			if (isNegative)
			{
				numbers[numbersIndex] -= str[sentenceIndex] - '0';
			}
			else {
				numbers[numbersIndex] += str[sentenceIndex] - '0';
			}

			if (!(isDigit(str[sentenceIndex + 1])))
			{
				numbersIndex++;
				isNegative = false;
			}
		}
		sentenceIndex++;
	}
	intsArrSize = numbersIndex;
	return numbers;
}

int main()
{
	char* str = new char[101];

	std::cout << "Enter sentence: ";
	std::cin.getline(str, 101);

	int arrSize = 0;
	int* numbersArr = extractInts(str, strlen(str), arrSize);
	printArr(numbersArr, arrSize);

	delete[] numbersArr;
	delete[] str;

	return 0;
}