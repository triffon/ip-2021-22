// ��� 3. �� �������� ��� ���� ����� N � M ����������� �� ��������� ������ ����� �� N �� M.

#include <iostream>
using namespace std;

int main()
{
	unsigned int N, M;
	cin >> N >> M;

	for (; N <= M; ++N)
	{
		cout << N << " ";
	}

	cout << endl;

	return 0;
}