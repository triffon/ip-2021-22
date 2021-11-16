#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // Първия ред със *
    for (int i = 0; i < n - 1; i++) {
        std::cout << ' ';
    }
    std::cout << "*\n";

    // Редовете от горната част на ромба
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            std::cout << ' ';
        }

        std::cout << '/';

        for (int j = 0; j < 2 * i - 1; j++) {
            std::cout << ' ';
        }
        std::cout << "\\\n";
    }

    // Редовете от долната част на ромба
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            std::cout << ' ';
        }

        std::cout << '\\';

        for (int j = 0; j < 2 * i - 1; j++) {
            std::cout << ' ';
        }
        std::cout << "/\n";
    }

    // Последния ред със *
    for (int i = 0; i < n - 1; i++) {
        std::cout << ' ';
    }
    std::cout << "*\n";

    return 0;
}
