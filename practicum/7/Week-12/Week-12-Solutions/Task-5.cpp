#include <iostream>

int fact(int n) {   //Task 5.
	if (n == 0) {
		return 1;
	}
	return fact(n - 1) * n;
}

int fib(int n) {    //Task 5.1
	if (n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	std::cout << fact(3) << '\n'; // -> 6
	std::cout << fib(9);         // -> 34
	return 0;
}