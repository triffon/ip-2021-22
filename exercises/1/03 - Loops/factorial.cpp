#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    int factorial{1};

    for (unsigned i{2}; i <= n; ++i)
    {
        factorial *= i;
    }

    std::cout << factorial;

    return 0;
}