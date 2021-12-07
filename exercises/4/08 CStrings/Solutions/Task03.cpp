#include <iostream>
#include <cstring>

void copySubString(char source[], unsigned start, unsigned count, char destination[])
{
	unsigned length = strlen(source);
	if (start >= length)
	{
		destination[0] = '\0';
		return;
	}

	//unsigned i = 0
	//for (; i < count && i < length - start; ++i)
	//{
	//	destination[i] = source[i + start];
	//}

	//destination[i] = '\0';

	unsigned limit = std::min(start + count, length);
	for (unsigned i = start; i < limit; ++i)
	{
		destination[i - start] = source[i];
	}

	destination[limit - start] = '\0';
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    char result[MAX_SIZE];

    unsigned startPosition;
    std::cout << "Start position of the substring: "; 
    std::cin >> startPosition;

	unsigned length;
    std::cout << "Length of the substring: "; 
    std::cin >> length;

    copySubString(str, startPosition, length, result);
    std::cout << "The substring is: " << result << std::endl;

    return 0;
}