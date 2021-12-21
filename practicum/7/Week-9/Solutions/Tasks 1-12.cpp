#include<iostream>

//Task 1
int input() {
	int n;
	
	do {
		std::cin >> n;
	} while (n < 0);

	return n;
}

//Task 2
void function() {
	int a = 5;
	int* ptr = &a;

	std::cout << "address of a: " << &a << std::endl;
	std::cout << "value of ptr: " << ptr << std::endl;

	a = 6;

	std::cout << "value of *ptr: " << *ptr << std::endl;
}

//Task 3
void changeValue(int* a) {
	*a += 5;
}

void changeValue(int& a) {
	a += 5;
}

//Task 4
void input(int* arr, int size) {
	/*for (int i = 0; i < size; ++i)
		std::cin >> arr[i];*/

	while (size) {
		std::cin >> *arr;
		size--;
		arr++;
	}
}

void print(int* arr, int size) {
	while (size) {
		std::cout << *arr;
		size--;
		arr++;
	}

	std::cout << std::endl;
}

void removeAt(int* arr, int& size, int index) {
	size--;

	arr += index;
	int newSize = size - index;
	//масивът вече започва от index, не от 0
	//съответно размерът му е с index по-малък

	while (newSize) {
		*arr = *(arr + 1);
		arr++;
		newSize--;
	}
}

void removeElement(int* arr, int& size, int element) {
	for (int i = 0; i < size; ++i)
		if (arr[i] == element)
			removeAt(arr, size, i);
}

//Task 5
void sumIntoFirst(int& first, int second) {
	first = first + second;
}

//Task 6
void swap(int* arr1, int* arr2, int size) {
	for (int i = 0; i < size; ++i) {
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

//Task 7
bool areSameLength(char* str1, char* str2) {
	while (*str1 && *str2) {
		++str1;
		++str2;
	}

	return !(*str1 - *str2); //Aко са с равна дължина, и двете ще са '\0' и разликата ще е 0
}

//Task 8
bool areEqual(char* str1, char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2)
			return false;
		++str1;
		++str2;
	}

	return !(*str1 - *str2);
}

//Task 9
void printLowercase(char* str) {
	while (*str) {
		if (*str >= 'a' && *str <= 'z')
			std::cout << *str;

		++str;
	}
	std::cout << std::endl;
}

void printUppercase(char* str) {
	while (*str) {
		if (*str >= 'A' && *str <= 'Z')
			std::cout << *str;

		++str;
	}
	std::cout << std::endl;
}

void printDigits(char* str) {
	while (*str) {
		if (*str >= '0' && *str <= '9')
			std::cout << *str;

		++str;
	}
	std::cout << std::endl;
}

const int MAX_LEN = 1024;

//Task 10
void printWords(char* str) {
	char word[MAX_LEN];
	char* pWord;;

	while (*str) {
		pWord = word;

		while (*str != ' ' && *str) {
			*pWord = *str;
			++pWord;
			++str;
		}

		*pWord = '\0';
		std::cout << word << std::endl;
		
		if(*str)
			++str;
	}
}

//Task 12
void partialCopy(char* src, char* dest, int size) {
	for (int i = 0; i < size; ++i)
		dest[i] = src[i];

	dest[size] = '\0';
}

bool isSubstring(char* str1, char* str2) {
	char copy[MAX_LEN];
	int len = strlen(str2);

	while (*str1) {
		partialCopy(str1, copy, len);
		if (areEqual(copy, str2))
			return true;
		++str1;
	}

	return false;
}

int main() {
	char str[] = "Hellooo, World";
	char str2[] = "Hell no, World";
	char hello[] = "ello";

	std::cout << std::boolalpha << areSameLength(str, str2) << std::endl;
	std::cout << std::boolalpha << areEqual(str, str2) << std::endl;
	std::cout << std::boolalpha << isSubstring(str, hello) << std::endl;

	char line[] = "Hello, it's 22:47 and I've been doing this for 2 hours.";

	printLowercase(line);
	printUppercase(line);
	printDigits(line);

	printWords(line);

	return 0;
}