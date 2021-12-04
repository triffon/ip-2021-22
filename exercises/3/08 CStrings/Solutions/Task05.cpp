#include <algorithm>
#include <cstring>
#include <iostream>

void reverse(char sentence[], unsigned start, unsigned end)
{
	unsigned middle = (end - start + 1) / 2;

	for (unsigned i = 0; i < middle; ++i)
	{
		std::swap(sentence[i + start], sentence[end - i]);
	}
}

void reverseWordsInSentence(char sentence[])
{
	unsigned length = strlen(sentence);

	unsigned countChars = 0;

	for (unsigned i = 0; i <= length; ++i)
	{
		// ако разделителите са запетая (,), интервал и точка (.)??
		if (sentence[i] == ' ' || i == length)
		{
			reverse(sentence, i - countChars, i - 1);
			countChars = 0;
		}
		else
		{
			++countChars;
		}
	}
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

	reverseWordsInSentence(str);

	std::cout << str << std::endl;

    return 0;
}