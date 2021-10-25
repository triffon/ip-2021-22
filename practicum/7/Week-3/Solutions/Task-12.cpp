#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;
	int numberMinusOne = number - 1;
	std::cout << !(number & numberMinusOne); //AND

	return 0;
}