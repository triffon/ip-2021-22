// Зад 7. Прочетете поредица от цели числа (поне едно), разделени със запетая, 
// завършваща с “;” (поредицата). Изведете най-малкото, най-голямото и средно аритметичното
// им.

#include <iostream>
using namespace std;

int main()
{
	char currChar = ',';
	int sum = 0;
	int numCount = 0;
	int min, max;

	while (currChar != ';')
	{
		int currNum;
		cin >> currNum;
		cin >> currChar;

		if (numCount == 0)
		{
			min = currNum;
			max = currNum;
		}

		++numCount;
		sum += currNum;
		if (min > currNum) min = currNum;
		if (max < currNum) max = currNum;
	}

	cout << min << " " << max << " " << (double) sum / numCount << endl;

	return 0;
}