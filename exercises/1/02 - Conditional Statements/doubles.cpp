#include <iostream>
#include <cmath>

int main()
{
    double x{0.0001};
    double y{0.0003 / 3};

    std::cout << std::boolalpha << (x == y) << '\n';

    const double eps{
        0.00001
    };

    // better for smaller numbers
    std::cout << std::boolalpha << (std::fabs(x - y) <= eps) << '\n';

    // better for bigger numbers
    std::cout << std::boolalpha << (std::fabs(x - y) <= eps * (std::max(x, y)));

    return 0;
}