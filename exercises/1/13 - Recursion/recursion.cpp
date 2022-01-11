#include <iostream>

unsigned factorial(unsigned n)
{
    // bottom
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

unsigned fib(unsigned n)
{
    if (n < 2)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

// a ^ b
unsigned exp(unsigned a, unsigned b)
{
    if (b == 0)
    {
        return 1;
    }

    return a * exp(a, b - 1);
}

unsigned fast_exp(unsigned a, unsigned b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        // b = 2k
        // a ^ 2k
        // a^2^k
        return exp(a * a, b / 2);
    }

    return a * exp(a * a, b / 2);
}

/*
e(a, 0) = 1
e(a, b) = a * e(a, b - 1)
*/

int main()
{
    std::cout << exp(2, 10);
    return 0;
}