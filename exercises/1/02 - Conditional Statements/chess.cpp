#include <iostream>

int main()
{
    int x1;
    int y1;
    int x2;
    int y2;

    std::cin >> x1 >> x2 >> y1 >> y2;

    const bool clashing_rooks{
        (x1 == y1) || (x1 == y2)
    };

    const bool clashing_bishops{
        ((x1 - y1) == (x2 - y2)) || ((x1 + x2) == (y1 + y2))
    };

    const bool clashing_queens{
        clashing_rooks || clashing_bishops
    };

    std::cout << std::boolalpha << clashing_rooks << '\n';
    std::cout << std::boolalpha << clashing_bishops << '\n';
    std::cout << std::boolalpha << clashing_queens << '\n';
    return 0;
}