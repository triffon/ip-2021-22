#include <cmath>
#include <iostream>

bool is_prime(unsigned number)
{
    bool prime{number > 1};

    for (unsigned j{2}; j <= sqrt(number) && prime; ++j)
    {
        prime = (number % j != 0);
    }

    return prime;
}

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned counter{0};

    for (unsigned i{0}, number; i < n; ++i)
    {
        std::cin >> number;

        counter += is_prime(number);
    }

    std::cout << counter << '\n';

    return 0;
}