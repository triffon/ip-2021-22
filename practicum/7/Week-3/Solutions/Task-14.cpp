#include <iostream>

using namespace std;

int toBinary(int number) {
	if (number == 0) {
		return 0;
	}
	else {														//Task 14.1
		return (number % 2 + 10 * toBinary(number / 2));
	}
}

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;

	/*int numberInBinary = 0;
	int multiplier = 1;
	for (int i = number; i > 0; i /= 2) {
		numberInBinary += (number % 2) * multiplier;    //Task 14
		multiplier *= 10;
		number /= 2;
	}

	cout << "Binary representation: " << numberInBinary << endl;*/

	cout << "Binary recursive solution: " << toBinary(number) << endl;


	return 0;
}