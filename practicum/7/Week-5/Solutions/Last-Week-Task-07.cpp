//�� �� ������ ��������, ����� �� �������� ����� x <= 10 � y <= 10 ������� �� ������:
//-������������
//-�����


#include<iostream>

int main() {

	int x, y;
	std::cin >> x >> y;

	//������������
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j){
			std::cout << "* ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//�����
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	return 0;
}