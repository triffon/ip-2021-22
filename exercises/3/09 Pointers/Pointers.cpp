#include <iostream>

const int MAX_SIZE = 10;

void read(int a[], int n)
{
	int* begin = a;
	int* end = a + n;

	for (int* current = begin; current != end; ++current)
	{
		std::cin >> *current;
	}
}

void read(int* begin, int* end)
{
	for (int* current = begin; current != end; ++current)
	{
		std::cin >> *current;
	}
}

void print(const int* begin, const int* end)
{
	for (const int* current = begin; current != end; ++current)
	{
		std::cout << *current << ' ';
	}
}

bool isMember(const int* begin, const int* end, int element)
{
	for (const int* current = begin; current != end; ++current)
	{
		if (*current == element)
			return true;
	}

	return false;
}

int countDistinctElements(const int* begin, const int* end)
{
	int distinct[MAX_SIZE];
	int count = 0;

	for (const int* current = begin; current != end; ++current)
	{
		if (!isMember(distinct, distinct + count, *current))
		{
			// *(distinct + count) = *current;

			distinct[count] = *current;
			++count;
		}
	}

	return count;
}

int length(const char* str)
{
	const char* current = str;
	while (*current != '\0')
	{
		++current;
	}

	return current - str;
}

char* strchr(char* str, char c)
{
	char* current = str;
	while (*current != '\0' && *current != c)
	{
		++current;
	}

	if (*current == c)
		return current;

	return nullptr;
}

bool isPrefix(char* str, char* prefix)
{
	char* current_str = str;
	char* current_prefix = prefix;

	while (*current_str == *current_prefix && *current_prefix != '\0')
	{
		++current_str;
		++current_prefix;
	}

	return *current_prefix == '\0';
}

char* substr(char* str, char* substr)
{
	char* current = str;
	while (*current != '\0')
	{
		if (isPrefix(current, substr))
			return current;

		++current;
	}

	return nullptr;
}

int main()
{
	char str[] = "abcdefgh";
	char str2[] = "ded";

	char* position = substr(str, str2);
	if (position)
	{
		std::cout << position << std::endl;
	}
	else
	{
		std::cout << "The substring is not found!" << std::endl;
	}

	char* ptrC = strchr(str, 'c');
	if (ptrC)
	{
		std::cout << ptrC << std::endl;
	}
	else
	{
		std::cout << "The character is not found!" << std::endl;
	}

	std::cout << length(str) << std::endl;

	int a[MAX_SIZE];
	int n = 5;

	read(a, a + n);
	print(a, a + n);

	std::cout << "Count distinct: " << countDistinctElements(a, a + n) << std::endl;
	
	// указатели и масиви...
	int* current = a;
	current = current + 3;
	std::cout << *current << std::endl;
	
	//int x = 5;
	//int y = 10;

	//const int* ptrX = &x;
	//// указателят не може да бъде използван за промяна на x
	////*ptrX = 7;
	//ptrX = &y;

	//x = 13;

	//int* const cptrX = &x;
	//// указателят не може да бъде пренасочен към друга променлива
	////cptrX = &y;
	//*cptrX = 10;

	//// достъп единствено за четене
	//// указателят не може да бъде пренасочен
	//const int* const p = &x;

	return 0;
}