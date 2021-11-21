#include<iostream>

//task 3
void fibonacci(unsigned n) {
    if (n == 0)
        std::cout << "There are no elements to print!\n";

    else {
        unsigned fib1 = 0, fib2 = 1;
        unsigned fib3;

        for (int i = 0; i < n; ++i) {
            fib3 = fib1 + fib2;
            std::cout << fib1 << " ";
            fib1 = fib2;
            fib2 = fib3;
        }
        std::cout << std::endl;
    }
}

int main() {

    fibonacci(5);

	return 0;
}