#include <iostream>
#include <cmath>

int main()
{
    double px;
    double py;

    double cx;
    double cy;

    double r;

    std::cin >> px >> py >> cx >> cy >> r;

    const double side1{
        cx - px
    };

    const double side2{
        cy - py
    };

    const double squared_distance{
        side1 * side1 - side2 * side2
    };

    const double eps{0.0001};

    const double squared_radius{
        r * r
    };

    const double delta{
        std::fabs(squared_distance - squared_radius)
    };

    if (squared_distance < squared_radius && delta > eps) {
        std::cout << "inside\n";
    } else if (squared_distance > squared_radius && delta > eps) {
        std::cout << "outside\n";
    } else {
        std::cout << "on\n";
    }

    return 0;
}
