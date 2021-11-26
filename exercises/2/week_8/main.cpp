//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <iostream>
#include <cstring>

using namespace std;

void selectionSort(int arr[], int n)
{
	int min_idx;

	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void f(const char message[]) {
	cout << message;
}

int main() {

	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };

	//bubbleSort(arr, 15);

	//for (size_t i = 0; i < 15; i++)
	//{
	//	cout << arr[i] << " ";
	//}

	char message[] = "super qkoto";

	//message[3] = '\0';
	//cout << message;
	//message[3] = 'e';
	//cout << message;

	//for (int i = 0; message[i] != '\0'; i++)
	//{
	//	if (message[i] == ' ')
	//	{
	//		message[i] = ',';
	//	}
	//}
	//f(message);


	const char message2[] = "super qkoto";
	char all[25] = "";

	//cout << message;
	//cout << strlen(message);
	//strcpy(message, message2);
	//strcpy_s(message, strlen(message2) + 1, message2);
	//strcat(all, message);
	//strcat(all, message2);
	//cout << message;

	//cout << all;
	//cout << strcmp(message, message2);


	return 0;
}