#include <iostream>
#include <cstring>

bool isPalindrome(char str[])
{
	unsigned end = strlen(str);
	unsigned middle = end / 2;

	for (unsigned i = 0; i < middle; ++i)
	{
		if (str[i] != str[end - i - 1])
			return false;
	}

	return true;
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    std::cout << "Is " << str << " palindrome? " << std::boolalpha << isPalindrome(str) << std::endl;

    return 0;
}