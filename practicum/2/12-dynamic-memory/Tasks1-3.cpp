#include <iostream>
#include <cstring>

/*3. Напишете функция, която по подадени два символни низа връща указател
към динамично заделен символен низ, който е конкатенацията на двата подадени низа.*/
// Returns allocated memory. Returns nullptr if no space;
char* myStrCat(char* str1, char* str2)
{
	int newSize = strlen(str1) + strlen(str2) + 1;

	char* newStr = new (std::nothrow) char[newSize];
	if (!newStr)  // !newStr <==> (newStr == nullptr)    
		return nullptr;

	strcpy(newStr, str1);
	strcat(newStr, str2);

	newStr[newSize - 1] = '\0';

	return newStr;
}


/*1.  Напишете функция, която по подаден размер заделя динамична памет за масив
(от цели числа) с подадения размер и връща указател към него.*/
int* allocateArray(int size)
{
	int* arr = new (std::nothrow) int[size];
	return arr;
}


/*2. Напишете функция, която добавя елемент на края на динамично заделен масив.*/
int* addToArray(int *arr, int size, int& capacity, int value)
{
	if (size >= capacity)
	{
		int* newArr = new (std::nothrow) int[capacity + 1];

		if (!newArr)
			return nullptr;

		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		++capacity;
	}

	arr[size] = value;
	return arr;
}

int main()
{

	return 0;
}