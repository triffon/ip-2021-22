#include <iostream>

void swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}

void reverseArray(int* arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	swap(arr[start], arr[end]);

	reverseArray(arr, start + 1, end - 1);
}

int main()
{
	int arr[] = { 1,2,3,4 };
	reverseArray(arr, 0, 3);  //3 = size - 1

	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i];
	}

	return 0;
}