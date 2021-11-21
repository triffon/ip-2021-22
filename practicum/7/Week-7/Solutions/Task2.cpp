#include<iostream>

//task 2
unsigned greatest_common_divisor(unsigned a, unsigned b) {
    unsigned tmp;

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main() {

    std::cout << "The gcd of (18, 24) is " 
        << greatest_common_divisor(18, 24) << std::endl;

    std::cout << "The gcd of (2, 3) is " 
        << greatest_common_divisor(2, 3) << std::endl;

	return 0;
}