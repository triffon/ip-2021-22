// ��� 8. �� �������� ���� ������������� ����� N ��������� N �� ���� ���� ����� � 
// �������� ���-�������� �� ���.

#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;
	int max1;
	int number;

	cin >> number;
	max1 = number;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> number;
		max1 = (number > max1) ? number : max1;
	}

	cout << max1 << endl;

	return 0;
}