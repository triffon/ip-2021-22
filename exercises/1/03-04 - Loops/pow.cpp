#include <iostream>

int main()
{
    double a;
    unsigned b;

    std::cin >> a >> b;

    int pow{1};

    for (unsigned i{0}; i < b; ++i)
    {
        pow *= a;
    }

    std::cout << pow;

    return 0;
}