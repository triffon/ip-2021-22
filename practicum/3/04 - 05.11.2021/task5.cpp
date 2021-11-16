#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        int n = i;
        int digitSum = 0;

        while (n != 0) {
            digitSum += n % 10;
            n /= 10;
        }

        if (i % digitSum == 0) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
