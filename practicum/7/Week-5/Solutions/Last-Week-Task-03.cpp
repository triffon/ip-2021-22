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

/*�� �� ������ ��������, ����� �������� � ���������:
- ���������� �� ������ 1 - 1/2 + 1/3 - 1/4 + ... + (-1)^(n-1)*1/n;*/

/*�� �� ������ ��������, ����� �� �������� ���� ������ ����� � ������������. ����� n �� 
������ �����������, ��� ��������� �������� �������: n = (ak)^k + (ak-1)^k + � + (a2)^k + (a1)^k, 
����� ������ �� ������� �� �������, ���������� �� ������ ���� �� �������, �� � ������ �����.*/

/*�� �� ������ ��������, ����� ������ ������ ������������� �����, ����� ���� �� ������� ��� 
����� � ����� �� ����� �� ������� ��� �����.*/