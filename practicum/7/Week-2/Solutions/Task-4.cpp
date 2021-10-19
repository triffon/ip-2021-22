#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "Enter cube side: ";		//Кубър ни работи с цели числа, ако искаме пресметнем обема на куб
	cin >> N;							// с страни реални числа ни трябва double/float

	int cubeArea = N * N * N;
	cout << "Cube area: " << cubeArea << endl;

	return 0;
}