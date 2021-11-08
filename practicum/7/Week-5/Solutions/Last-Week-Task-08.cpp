//триъгълника на Паскал
#include<iostream>

int main() {

    int binomial = 1;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        //празни
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << " ";

        //числа
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                binomial = 1;
            else
                binomial = binomial * (i - j + 1) / j;

            std::cout << binomial << " ";
        }

        std::cout << std::endl;
    }

	return 0;
}