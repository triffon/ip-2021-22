#include <iostream>

int countDigits(unsigned n)
{
	if (n <= 9)
		return 1;

	return 1 + countDigits(n / 10);
}

bool hasDigit(unsigned n, unsigned k)
{
	if (n <= 9)
		return n == k;

	int lastDigit = n % 10;

	return lastDigit == k || hasDigit(n / 10, k);
}

int sumDigit(unsigned n)
{
	if (n <= 9)
		return n;

	return n % 10 + sumDigit(n / 10);
}

// 0, 1, 2, ...
void read(int* array, int n)
{
	if (n <= 0)
		return;

	std::cin >> array[0];

	read(array + 1, n - 1);
}

// n - 1, n - 2, .... , 0
void readReverse(int* array, int n)
{
	if (n <= 0)
		return;

	std::cin >> array[n - 1];

	readReverse(array, n - 1);
}

void printInOrder(const int* array, int n)
{
	if (n <= 0)
		return;

	std::cout << array[0] << ' ';

	printInOrder(array + 1, n - 1);
}

void printReverse(const int* array, int n)
{
	if (n <= 0)
		return;

	// първо извеждаме всички останали, 
	printReverse(array + 1, n - 1);

	// накрая извеждаме първия
	std::cout << array[0] << ' ';
}

int minElement(int* array, int n)
{
	if (n == 1)
		return array[0];

	int minRest = minElement(array + 1, n - 1);

	if (array[0] < minRest)
		return array[0];

	return minRest;
}

const int MAX_SIZE = 100;

int main()
{
	int array[MAX_SIZE];
	int n = 5;

	read(array, n);

	std::cout << "In order: ";
	printInOrder(array, n);

	std::cout << "\nReversed: ";
	printReverse(array, n);

	std::cout << "\nMin element: " << minElement(array, n) << std::endl;

	int number;
	std::cin >> number;

	std::cout << "Number of digits: " << countDigits(number) << std::endl;
	std::cout << "Sum of digits: " << sumDigit(number) << std::endl;

	std::cout << "Is 3 in the number? " << std::boolalpha << hasDigit(number, 3) << std::endl;

	return 0;
}