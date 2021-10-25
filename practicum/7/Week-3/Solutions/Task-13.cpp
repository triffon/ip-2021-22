#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;
	/* Знаем, че едно число е нечетно ако последния бит в двоичния му запис е 1.
	* Значи ако приложим AND върху number и числото 1 (0001), и получим различно от 1 => числото е четно.
	*/
	cout << boolalpha << ((number & 1) != 1) << endl;

	//Друг начин е:
	cout << boolalpha << (number % 2 == 0);


	return 0;
}