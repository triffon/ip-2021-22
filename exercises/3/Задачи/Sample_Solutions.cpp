#include <iostream>

int replace(int number, int toBeReplaced, int newDigit)
{
	if (number < 0)
		return -replace(-number, toBeReplaced, newDigit);

	if (number == 0)
		return 0;

	int newBeginning = replace(number / 10, toBeReplaced, newDigit);

	int lastDigit = number % 10;
	if (lastDigit == toBeReplaced)
	{
		return newBeginning * 10 + newDigit;
	}

	return newBeginning * 10 + lastDigit;
}

int main_04()
{
	int number = replace(-1020, 0, 4);
	std::cout << number << std::endl;

	return 0;
}

bool isPowerOf2(unsigned n)
{
	if (n == 1)
		return true;

	if (n % 2 != 0)
		return false;

	return isPowerOf2(n / 2);
}

int main_05()
{
	std::cout << "Is " << 46 << " power of 2: " << std::boolalpha << isPowerOf2(46) << std::endl;
	std::cout << "Is " << 16 << " power of 2: " << std::boolalpha << isPowerOf2(16) << std::endl;

	return 0;
}

int sum(int a, int b, int step)
{
	if (a > b)
		return 0;

	return a + sum(a + step, b, step);
}

int sumTR(int a, int b, int step, int result, int current)
{
	if (current > b)
		return result;

	return sumTR(a, b, step, result + current, current + step);
}

int sum2(int a, int b, int step)
{
	return sumTR(a, b, step, 0, a);
}

int main_06()
{
	std::cout << sum(1, 10, 1) << std::endl;
	std::cout << sum2(1, 10, 1) << std::endl;

	return 0;
}

int binarySearch(const int* array, int start, int end, int element)
{
	if (start >= end)
		return -1;

	int middle = start + (end - start) / 2;
	
	if (array[middle] == element)
		return middle;

	if (array[middle] < element)
		return binarySearch(array, middle + 1, end, element);

	return binarySearch(array, start, middle - 1, element);
}

int main_07()
{
	int arr[] = { 7, 8, 4, 10, 40 };
	
	int x = 10;
	int n = sizeof(arr) / sizeof(int);
	
	int result = binarySearch(arr, 0, n - 1, x);
	if (result == -1)
	{
		std::cout << "The element is not present in the array\n";
	}
	else
	{
		std::cout << "The element is found at position " << result << std::endl;
	}

	return 0;
}

int findMaxElement(const int* array, int start, int end)
{
	if (start == end) 
		return array[start];

	int middle = start + (end - start) / 2;

	int maxFirstHalf = findMaxElement(array, start, middle);
	int maxSecondHalf = findMaxElement(array, middle + 1, end);

	if (maxFirstHalf > maxSecondHalf)
		return maxFirstHalf;

	return maxSecondHalf;
}

int findMaxElement(const int* array, int n)
{
	return findMaxElement(array, 0, n - 1);
}

// x + y,
// yx - xy
int findY(int x, int sum, int diff)
{
	if (x >= 10)
		return 0;

	int y = sum - x;
	if(y >= 10)
		return findY(x + 1, sum, diff);

	int yx = y * 10 + x;
	int xy = x * 10 + y;

	if (diff == yx - xy)
		return xy;

	return findY(x + 1, sum, diff);
}

// 35
// 8, 53 - 35 = 18

// 53
// 8, -18

int findXY(int sum, int diff)
{
	return findY(1, sum, diff);
}

int main_13()
{
	std::cout << findXY(8, -18) << std::endl;
	return 0;
}

// задача 11
void insertToSorted(int* array, int& n, int capacity, int elem)
{
	if (n >= capacity)
		return;

	if (n == 0)
	{
		array[0] = elem;
		++n;

		return;
	}

	if (array[n - 1] <= elem)
	{
		array[n] = elem;
		++n;
	}
	else
	{
		array[n] = array[n - 1];

		int sizeWithoutLast = n - 1;
		insertToSorted(array, sizeWithoutLast, capacity, elem);

		++n;
	}
}

// задача 14
const char* mother(const char* person, const char* database[][3], int n)
{
	if (n == 0)
		return nullptr;

	if (strcmp(database[0][0], person) == 0)
		return database[0][1];

	return mother(person, database + 1, n - 1);
}

const char* father(const char* person, const char* database[][3], int n)
{
	if (n == 0)
		return nullptr;

	if (strcmp(database[0][0], person) == 0)
		return database[0][2];

	return father(person, database + 1, n - 1);
}

bool inheritor(const char* a, const char* b, const char* database[][3], int n)
{
	if (!b)
		return false;

	const char* mb = mother(b, database, n);
	const char* fb = father(b, database, n);

	//if (mb == nullptr && fb == nullptr)
	//	return false;

	//if (mb == nullptr)
	//{
	//	if (strcmp(fb, a) == 0)
	//		return true;

	//	return inheritor(a, fb, database, n);
	//}
	//
	//if (fb == nullptr)
	//{
	//	if (strcmp(mb, a) == 0)
	//		return true;

	//	return inheritor(a, mb, database, n);
	//}

	return
		fb && (strcmp(fb, a) == 0 || inheritor(a, fb, database, n)) ||
		mb && (strcmp(mb, a) == 0 || inheritor(a, mb, database, n));
}

bool inheritorMotherLine(const char* a, const char* b, const char* database[][3], int n)
{
	const char* mb = mother(b, database, n);

	if (!mb)
		return false;

	return strcmp(a, mb) == 0 || inheritor(a, mb, database, n);
}

// задача 2 от 
// Задачи за поправителен изпит по УП (КН) 2018/19
// moodle

bool isValid(int x, int y)
{
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}

bool findWord(int x, int y, const char* word, char c[][3])
{
	if (*word == '\0')
		return true;

	if (!isValid(x, y) || c[x][y] != *word)
		return false;

	return
		findWord(x - 1, y, word + 1, c) ||
		findWord(x + 1, y, word + 1, c) ||
		findWord(x, y - 1, word + 1, c) ||
		findWord(x, y + 1, word + 1, c);
}

bool findWord(const char* word, char c[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (c[i][j] == *word)
			{
				if (findWord(i, j, word, c))
					return true;
			}
		}
	}

	return false;
}

bool crossword(char c[][3], char words[][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (!findWord(words[i], c))
			return false;
	}

	return true;
}

int main()
{
	//char c[3][3] = { { 'c', 'a', 't' }, {'w', 'h', 'o'} , {'w', 'i', 'n'} };
	//char words[][10] = {"cat", "chat", "not"};

	//std::cout << std::boolalpha << crossword(c, words, 3) << std::endl;

	const char* db[][3] = { {"A", "B", "C"}, {"B", "D", "E" }, {"C", "F", "G"} };

	//const char* m = mother("E", db, 3);
	//if (m != nullptr)
	//	std::cout << m << std::endl;

	std::cout << std::boolalpha << inheritorMotherLine("F", "A", db, 3) << std::endl;

	//int array[] = { 1, 2, 3, 5, 6 };
	//int n = 5;

	//insertToSorted(array, n, 5, 0);

	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << array[i] << ' ';
	//}

	//int array[] = { 5, 1, 2, 6, 3, -1 };
	//std::cout << findMinElem(array, 0, 5) << std::endl;

	//std::cout << replace(102, 0, 4) << std::endl;

	return 0;
}
