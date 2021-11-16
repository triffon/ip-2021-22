#include <iostream>

using namespace std;

int compute(double x, double y)
{
	return x - y;
}

int sum(int x, int y, double a, char ch = 'e', int z = 3);



void dosth() {

	int x;
	cout << "Void function";
	cin >> x;
	x += 10;
	cout << x;
	x = sum(3,4, 3.3);
	//if (x > 10)
	//{
	//	return;
	//}


	cout << x;

}

int increment(int parameter);


int main() {


	int argument = 5;
	cout << endl << (double)increment(argument) + sum(6,4,5.6) + increment(argument);
	cout << endl << argument;

	//int numbers[50];
	//int size;
	//cin >> size;

	//for (int i = 0; i < size; i++) {
	//	cin >> numbers[i];
	//}

	//bool isSizePrime = true;
	//for (int i = 2; i < size; i++) {
	//	if (size % i == 0) {
	//		isSizePrime = false;
	//		break;
	//	}
	//}

	//if (isSizePrime) {
	//	for (int i = 0; i < size; i++) {
	//		bool isNumberPrime = true;
	//		for (int k = 2; k < numbers[i]; k++) {
	//			if (numbers[i] % k == 0) {
	//				isNumberPrime = false;
	//				break;
	//			}
	//		}
	//		cout << numbers[i] << " is : " << (isNumberPrime ? "prime" : "not prime") << endl;
	//	}
	//}
	//cout << sum(3, 5, 4.5, 'a', 11);

	//dosth();

	return 0;
}

int compute(int x, int y = 2);

int increment(int parameter)
{
	parameter += 10;
	cout << parameter;
	return parameter;
}

int sum(int x, int y, double a, char ch, int z)
{
	int result = x + y;
	if (z > 10)
	{
		result = result + z + (int)ch;
	}
	if (y > 0)
	{
		compute(x);
	}
	else
	{
		compute(x, y);
	}
	return result;
}

int compute(int x, int y)
{
	return x - y;
}