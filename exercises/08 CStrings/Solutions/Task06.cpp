#include <cstring>
#include <iostream>

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int convertToDigit(char c)
{
	if (isDigit(c))
		return c - '0';

	return 0;
}

// дължина на низа - не повече от 9 ??
int convertToNumber(char str[])
{
	bool negativeSign = false;

	unsigned i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		++i;
	}

	if (str[0] == '-')
		negativeSign = true;

	int number = 0;
	while(str[i] && isDigit(str[i]))
	{
		number = number * 10 + convertToDigit(str[i]);
		++i;
	}

	if (number && negativeSign)
		number = -number;

	return number;
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

	std::cout << convertToNumber(str) << std::endl;
    return 0;
}