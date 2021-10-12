#include <iostream>

int main()
{
    int a;
    int b;
    std::cin >> a >> b;

    bool a_is_min{a <= b};
    bool b_is_min{a > b};

    int min{
        a_is_min * a + b_is_min * b
    };

    std::cout << min << std::endl;

    return 0;
}