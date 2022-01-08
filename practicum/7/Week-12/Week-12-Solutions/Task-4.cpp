#include <iostream>

int sumDigits(int n)
{
    if (n < 10)
    {
        return n % 10;
    }

    return n % 10 + sumDigits(n / 10);
}


int main()
{
    std::cout << sumDigits(1234); // -> 10
    return 0;
}