#include <cstring>
#include <iostream>

unsigned countWordsWithMinLength(char str[], unsigned minWordLength)
{
	unsigned countWords = 0;
	unsigned countChars = 0;

	unsigned strLength = strlen(str);

	// за да можем да преброим и последната дума,
	// цикълът е до терминиращата 0, включителн
	for (unsigned i = 0; i <= strLength; ++i)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (countChars >= minWordLength)
			{
				++countWords;
			}

			countChars = 0;
		}
		else
		{
			++countChars;
		}
	}

	return countWords;
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    std::cout << "Count words longer than 3: " << countWordsWithMinLength(str, 3) << std::endl;

    return 0;
}