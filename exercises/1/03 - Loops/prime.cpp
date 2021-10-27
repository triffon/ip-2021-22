#include <cmath>
#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned counter{0};

    for (unsigned i{0}, number; i < n; ++i)
    {
        std::cin >> number;

        // 0 and 1 are not prime
        bool is_prime{number > 1};

        for (unsigned j{2}; j <= sqrt(number) && is_prime; ++j)
        {
            is_prime = (number % j != 0);
        }

        counter += is_prime;
    }

    std::cout << counter << '\n';

    return 0;
}