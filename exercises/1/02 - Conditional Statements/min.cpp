#include <iostream>

int main()
{
    int a;
    int b;

    std::cin >> a >> b;

    int min_if;

    if (a <= b) {
        min_if = a;
    } else {
        min_if = b;
    }

    const int min_ternary{
        a <= b ? a : b
    };

    std::cout << min_if << ' ' << min_ternary << '\n';

    return 0;
}