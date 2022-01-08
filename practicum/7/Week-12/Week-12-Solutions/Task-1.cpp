#include <iostream>

void toBinary(int n)
{
    if (n == 0)
    {
        return;
    }

    toBinary(n / 2);
    std::cout << n % 2;
}

int main() {
    int number = 10;
    toBinary(number);

    return 0;
}