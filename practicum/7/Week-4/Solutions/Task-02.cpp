//�� �� ������ ��������, ����� �� �������� ����� n � k(k > 0, k <= ���� �� ������� �� n) ������� �� ������ k - ���� ����� �� n:
//-������� ������
//-������ �������

#include<iostream>

int main() {
	int n, k;
	std::cin >> n >> k;

	int reverse = 0;
	int ctr = 0; //�� ����� �� ��� ����� ��� ���������

	//������� ������
	while (n) {
		ctr++;

		if (ctr == k)
			std::cout << n % 10;


		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	std::cout << std::endl;

	ctr = 0;//�� ����� ������

	//������ �������
	while (reverse) {
		ctr++;

		if (ctr == k) {
			std::cout << reverse % 10 << " ";
			break;
		}

		reverse /= 10;
	}

	std::cout << std::endl;

	return 0;
}