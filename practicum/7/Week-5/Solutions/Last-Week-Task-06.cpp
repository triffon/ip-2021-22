/*Да се напише програма, която по въведено число n <= 10 извежда числата до n в по следните начини:

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
    //1-ва фигура
    //
    for (int i = 0; i < n; ++i){
        //празни
        for (int j = 0; j < n - i - 1; ++j)
           std::cout << " ";

        //числа
        for (int j = 0; j <= i; j++)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //
    //2-ра фигура
    //
    for (int i = 0; i < n; ++i){
        //празни
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //числа
        for (int j = 0; j < n - i; ++j)
            std::cout << j + 1 << " ";
 
        std::cout << std::endl;
    }

    std::cout << std::endl;
    
    //
    //3-та фигура
    //
    for (int i = 0; i < n - 1; ++i) {
        //празни
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //числа
        for (int j = 0; j < n - i; ++j)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        //празни
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << " ";

        //числа
        for (int j = 0; j <= i; j++)
            std::cout << j + 1 << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //
    //4-та фигура
    //
    for (int i = 0; i < n - 1; ++i) {
        //празни
        for (int j = 0; j < i; j++)
            std::cout << " ";

        //числа
        for (int j = 0; j < n - i; ++j)
            if (j == 0 || j == n - i- 1)
                std::cout << i + 1 << " ";
            else
                std::cout << "  ";

        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        //празни
        for (int j = 0; j < n - i - 1; ++j)
                std::cout << " ";

        //числа
        for (int j = 0; j <= i; j++)
            if (j == i || j == 0)
                std::cout << i + 1 << " ";
            else 
                std::cout << "  ";

        std::cout << std::endl;
    }
    
	return 0;
}