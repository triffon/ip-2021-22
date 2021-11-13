#include <iostream>

int main() {
    // Вариант 1
    for (int i = 1000; i < 100000; i++) {
        int n = i;
        bool onlyEven = true;

        while (n != 0) {
            onlyEven &= (n % 10) % 2 == 0;
            n /= 10;
        }

        if (onlyEven) {
            std::cout << i << std::endl;
        }
    }

    // Вариант 2
    for (int thousands = 1; thousands <= 9; thousands += 2) {
        for (int hundreds = 0; hundreds <= 9; hundreds += 2) {
            for (int tens = 0; tens <= 9; tens+= 2) {
                for (int ones = 0; ones <= 9; ones += 2) {
                    std::cout << thousands << hundreds << tens << ones << std::endl;
                }
            }
        }
    }

    return 0;
}
