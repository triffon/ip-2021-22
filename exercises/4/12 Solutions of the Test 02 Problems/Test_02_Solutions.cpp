#include <iostream>

bool isLetterOrDigit(char c)
{
	return 
		c >= 'A' && c <= 'Z' ||
		c >= 'a' && c <= 'z' ||
		c >= '0' && c <= '9';
}

bool hasFinished(const char* str)
{
	return !isLetterOrDigit(*str);
}

int compare(const char* first, const char* second)
{
	while (!hasFinished(first) && !hasFinished(second) && *first == *second)
	{
		++first;
		++second;
	}

	if (hasFinished(first) && hasFinished(second))
		return 0;

	if (hasFinished(first))
		return -1;

	if (hasFinished(second))
		return 1;

	return *first - *second;
}

const char* minWord(const char* str)
{
	const char* startMinWord = nullptr;
	const char* currentWord = nullptr;

	while (*str)
	{
		if (isLetterOrDigit(*str))
		{
			if (!currentWord)
			{
				currentWord = str;
			}
		}
		else
		{
			if (currentWord)
			{

				if (!startMinWord)
				{
					startMinWord = currentWord;
				}
				else
				{
					if (compare(startMinWord, currentWord) > 0)
					{
						startMinWord = currentWord;
					}

					currentWord = nullptr;
				}
			}
		}

		++str;
	}

	return startMinWord;
}

const int MAX_LENGTH = 100;

int main_01()
{
	char str[MAX_LENGTH];
	std::cin.getline(str, MAX_LENGTH);

	const char* startMin = minWord(str);
	std::cout << startMin << std::endl;

	return 0;
}

const int MAX_SIZE = 30;

bool hasDuplicateDigits(int number)
{
	if (number < 0)
		number = -number;

	bool digits[10]{ false };

	while (number > 0)
	{
		short currentDigit = number % 10;

		if (digits[currentDigit])
			return true;

		digits[currentDigit] = true;
		number /= 10;
	}

	return false;
}

void shrinkToFit(int*& array, int n, int initialCapacity)
{
	if (n >= initialCapacity)
		return;

	int* newArray = new int[n] {};
	for (int i = 0; i < n; ++i)
	{
		newArray[i] = array[i];
	}

	delete[] array;
	array = newArray;
}

int* collect(int matrix[][MAX_SIZE], int n, int& count)
{
	int initialCapacity = n * n;
	int* result = new int[initialCapacity]{};
	count = 0;

	// под главния диагонал
	for (int diff = n - 1; diff >= 0; --diff)
	{
		for (int j = 0; j < n - diff; ++j)
		{
			// i - j = diff
			// i = j + diff
			// j + diff < n => j < n - diff

			int i = j + diff;

			if (hasDuplicateDigits(matrix[i][j]))
			{
				result[count] = matrix[i][j];
				++count;
			}
		}
	}

	// над главния диагонал
	for (int diff = 1; diff < n; ++diff)
	{
		for (int i = 0; i < n - diff; ++i)
		{
			// j - i = diff
			// j = i + diff
			// i + diff < n => i < n - diff

			int j = i + diff;
			
			if (hasDuplicateDigits(matrix[i][j]))
			{
				result[count] = matrix[i][j];
				++count;
			}
		}
	}

	shrinkToFit(result, count, initialCapacity);

	return result;
}

int main()
{
	int matrix[][MAX_SIZE] = 
					{	{1076, 1356, 1918}, 
						{-6252, 6766, 5525}, 
						{5524, 3176, 1716} 
					};

	int count = 0;
	int* result = collect(matrix, 3, count);

	for (int i = 0; i < count; ++i)
	{
		std::cout << result[i] << ' ';
	}

	delete[] result;
	return 0;
}

bool isSmallLetter(char c)
{
	return c >= 'a' && c <= 'z';
}

int findPosition(char c, const char* letters, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (letters[i] == c)
			return i;
	}

	return -1;
}

int getValue(char c, const char* letters, const int* values, int n)
{
	int index = findPosition(c, letters, n);

	if (index < 0)
		return 0;

	return values[index];
}

int calculate(const char* expr, const char* letters, const int* values, int n)
{
	int product = 1;
	int sum = 0;

	while (*expr)
	{
		if (isSmallLetter(*expr))
		{
			product = product * getValue(*expr, letters, values, n);
		}
		else
		{
			if (*expr == '+')
			{
				sum += product;
				product = 1;
			}
		}

		++expr;
	}

	return sum + product;
}

int main_03()
{
	const char* str = "a.b+b.c+d+a.c";

	char letters[] = { 'b', 'c', 'a', 'd' };
	int values[] = {5, 3, 2, 42};

	std::cout << calculate(str, letters, values, 4) << std::endl;

	return 0;
}