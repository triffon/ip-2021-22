#include <iostream>


void settingFirstElement(int* arr)
{
	arr[0] = 4;
	std::cout << *arr << '\n';

}



int main() {

	int n;
	std::cin >> n;

	//int* pointer = new int[n];

	//for (int i = 0; i < n; i++)
	//{
	//	std::cin >> pointer[i];
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << pointer[i];
	//}

	//delete[] pointer;

	int* container = new int[n];

	settingFirstElement(container);

	delete[] container;
	container = nullptr;

	std::cout << *container << '\n';


	char nameInput[64];
	std::cin >> nameInput;

	char* name = new char[strlen(nameInput) + 1];

	strcpy_s(name, strlen(nameInput) + 1, nameInput);


	return 0;
}