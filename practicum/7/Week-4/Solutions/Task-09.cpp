/*�� �� ������ ��������, ����� �� �������� ����� n ������� ����� ����� �����:

�� 1 �� n
�� 2 �� n
o� 3 �� n*/

#include<iostream>

int main() {

	int n;
	std::cin >> n;

	for (int i = 1; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	for (int i = 2; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	for (int i = 3; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	return 0;
}