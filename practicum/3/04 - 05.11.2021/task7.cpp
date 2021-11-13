#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ((i == j) ? '$' : '*');
        }

        std::cout << '$';

        for (int j = 0; j < n; j++) {
            std::cout << ((n - i - 1 == j) ? '$' : '*');
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 2 * n + 1; i++) {
        std::cout << '$';
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ((n - i - 1 == j) ? '$' : '*');
        }

        std::cout << '$';

        for (int j = 0; j < n; j++) {
            std::cout << ((i == j) ? '$' : '*');
        }
        std::cout << std::endl;

    }
    return 0;
}
