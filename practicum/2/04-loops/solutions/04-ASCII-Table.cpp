// Зад 4. Отпечатайте на конзолата всички символи от ASCII таблицата.

#include <iostream>
using namespace std;

int main()
{
	for (unsigned char i = 0; i <= 136; ++i)
	{
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
