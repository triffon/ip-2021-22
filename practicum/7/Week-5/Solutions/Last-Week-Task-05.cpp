/*Да се напише програма, която по въведено число n <= 10 извежда на екрана следните картинки:

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
до n-тия ред.*/

#include<iostream>

int main() {

    int n;

    do { //проверка на входа
        std::cin >> n;
    } while (n < 0 || n > 10);

    //първата фигура
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << "  ";

        for (int j = 0; j <= i; ++j)
            std::cout << "* ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    //втората фигура
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j)
            std::cout << "* ";

        std::cout << std::endl;
    }

	return 0;
}