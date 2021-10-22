#include <iostream>

int main()
{
    int num;

    std::cin >> num;

    if (num > 0) {
        std::cout << "positive\n";
    } else if (num < 0) {
        std::cout << "negative\n";
    } else {
        std::cout << "zero\n";
    }
    
    return 0;
}