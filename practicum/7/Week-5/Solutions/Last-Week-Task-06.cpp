/*�� �� ������ ��������, ����� �� �������� ����� n <= 10 ������� ������� �� n � �� �������� ������:

   1
  1 2
 1 2 3 
1 2 3 4 
  ...
  ...
1 2 3 4
 1 2 3
  1 2
   1
  ...
1 2 3 4
 1 2 3
  1 2 
   1
  1 2
 1 2 3 
1 2 3 4 
  ...
1     1
 2   2
  3 3 
   4
  3 3
 2   2 
1     1 
*/

#include<iostream>

int main() {

    int n;
    std::cin >> n;

    //
    //1-�� ������
    //
    for (int i = 0; i < n; ++i){
        //������
        for (int j = 0; j < n - i - 1; ++j)
           std::cout << " ";

        //�����
        for (int j = 0; j <= i; j++)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //
    //2-�� ������
    //
    for (int i = 0; i < n; ++i){
        //������
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //�����
        for (int j = 0; j < n - i; ++j)
            std::cout << j + 1 << " ";
 
        std::cout << std::endl;
    }

    std::cout << std::endl;
    
    //
    //3-�� ������
    //
    for (int i = 0; i < n - 1; ++i) {
        //������
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //�����
        for (int j = 0; j < n - i; ++j)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        //������
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << " ";

        //�����
        for (int j = 0; j <= i; j++)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //
    //4-�� ������
    //
    for (int i = 0; i < n - 1; ++i) {
        //������
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //�����
        for (int j = 0; j < n - i; ++j)
            if (j == 0 || j == n - i- 1)
                std::cout << i + 1 << " ";
            else
                std::cout << "  ";

        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        //������
        for (int j = 0; j < n - i - 1; ++j)
                std::cout << " ";

        //�����
        for (int j = 0; j <= i; j++)
            if (j == i || j == 0)
                std::cout << i + 1 << " ";
            else 
                std::cout << "  ";

        std::cout << std::endl;
    }
    
	return 0;
}