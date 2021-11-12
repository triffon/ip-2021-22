/*�� �� ������ ��������, ����� �� �������� ����� n <= 10 ������� �� ������ �������� ��������:

      *
    * *
  * * *
* * * *
  ...
  ...
* * * *
* * *
* *
*
�� n-��� ���.*/

#include<iostream>

int main() {

    int n;

    do { //�������� �� �����
        std::cin >> n;
    } while (n < 0 || n > 10);

    //������� ������
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << "  ";

        for (int j = 0; j <= i; ++j)
            std::cout << "* ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //������� ������
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j)
            std::cout << "* ";

        std::cout << std::endl;
    }

	return 0;
}