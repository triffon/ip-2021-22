//�� �� ������ ��������, ����� �� �������� ���� ����������� ����� n,
//�� �� �������� �� ���� ���� �����, � ���� ���� �� �� ��������� ������ �� ������� ��.

#include<iostream>

int main() {

	int n;
	std::cin >> n;

	int sum = 0;
	int current = 0;

	do {
		std::cin >> current;

		while (current) {
			sum += current % 10;
			current /= 10;
		}

		n--;
	} while (n);

	std::cout << sum << std::endl;

	return 0;
}