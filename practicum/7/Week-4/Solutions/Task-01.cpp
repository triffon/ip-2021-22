//�� �� ������ ��������, ����� �� �������� ����� n, ������� ������� �� �� ������.

#include<iostream>

int main() {
	int n;
	std::cin >> n;

	int reverse = 0;

	while (n) { //���� ������� ������� �� ���� �� ������� ������� �� � ��������� ���
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	while (reverse) {
		std::cout << reverse % 10 << " ";
		reverse /= 10;
	}

	std::cout << std::endl;

	return 0;
}