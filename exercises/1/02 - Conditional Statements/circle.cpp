#include <iostream>
#include <iomanip>

int main()
{
    double r;
    std::cin >> r;

    const double pi{3.14};

    const double perimeter{
        2 * pi * r
    };

    const double area{
        pi * r * r
    };

    std::cout <<  std::setprecision(2) << perimeter << ' ' << area << '\n';

    return 0;
}