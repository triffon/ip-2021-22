#include <iostream>

int main()
{
    unsigned number;

    std::cin >> number;

    unsigned counter{number == 0};

    unsigned sum{0};

    unsigned reversed_number{0};

    for (unsigned n{number}; n != 0; n /= 10)
    {
        // count number of digits
        counter++;

        const unsigned last_digit{n % 10};

        // sum odd digits
        sum += last_digit * (last_digit % 2 != 0);

        // reverse number
        reversed_number = reversed_number * 10 + last_digit;
    }

    std::cout << counter << '\n'
              << sum << '\n'
              << reversed_number << '\n';

    return 0;
}