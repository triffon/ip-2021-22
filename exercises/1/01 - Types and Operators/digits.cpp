#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    int ones{
        num % 10
    };
    int tens{
        num / 10 % 10
    };
    int hundreds{
        num / 100
    };

    int reversed_number{
        100 * ones + 10 * tens + hundreds
    };

    bool is_palindrome{
        // num == reversed_number
        ones == hundreds
    };

    int digits_sum{
        ones + hundreds + tens
    };

    std::cout << "Reversed number " << reversed_number << '\n'
              << "Number is palindrome " << is_palindrome << '\n'
              << "Sum of digits" << digits_sum << '\n';

    return 0;
}