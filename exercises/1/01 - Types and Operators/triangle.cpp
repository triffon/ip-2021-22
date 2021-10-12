#include <iostream>

#include <cmath>

int main()
{
    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;

    int p{a+b+c};
    double semiperimeter{p/2.0};
    double area{
        std::sqrt(
            semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c)
        )
    };

    std::cout << "Perimeter: " << p << '\n'
              << "Semiperimeter: " << semiperimeter << '\n'
              << "Area: " << area << '\n';

    return 0;
}