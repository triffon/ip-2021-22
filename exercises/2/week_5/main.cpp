#include <iostream>
using namespace std;

int main() {

	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter value for:[" << i << "] ";
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		arr[i] *= 2;
	}

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == 8)
		{

		}
	}


	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}


	char charArray[4] = { 'n', 'i', 'c', 'e' };

	for (int i = 0; i < 4; i++)
	{
		cout << charArray[i];
	}
	float a = 4.0;
	float b = 4.0;
	cout << (a == b);

	return 0;
}