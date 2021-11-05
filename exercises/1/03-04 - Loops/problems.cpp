#include <iostream>
#include <ios>
#include <cmath>
#include <algorithm>

bool strictly_increasing(unsigned n)
{
    int number;
    int last_number;
    bool result{true};

    if (n < 1)
    {
        return true;
    }

    std::cin >> last_number;

    for (unsigned i{1}; i < n; ++i)
    {
        std::cin >> number;
        
        if (number <= last_number)
        {
            result = false;
        }

        last_number = number;
    }

    return result;
}

unsigned longest_increasing_subsequence(unsigned n)
{
    int number;
    int last_number;

    if (n < 1)
    {
        return 0;
    }

    std::cin >> last_number;

    unsigned longest_length{1};
    unsigned current_length{1};

    for (unsigned i{1}; i < n; ++i)
    {
        std::cin >> number;
        
        if (number > last_number)
        {
            current_length++;
            longest_length = std::max(longest_length, current_length);
        }
        else
        {
            current_length = 1;
        }

        last_number = number;
    }

    n = 100;

    return longest_length;
}


double average()
{
    double input;
    double sum{};
    double count{};
    while (std::cin >> input)
    {
        sum += input;
        count++;

        std::cout << sum / count << '\n';
    }

    return sum / count;
}

unsigned largest_digit(unsigned n)
{
    unsigned max{0};
    
    for (; n != 0; n /= 10)
    {
        unsigned last_digit{n % 10};
        max = std::max(last_digit, max);   
    }

    return max;
}

unsigned smallest_digit(unsigned n)
{
    unsigned min{9};

    if (n == 0)
    {
        return 0;
    }
    
    for (; n != 0; n /= 10)
    {
        unsigned last_digit{n % 10};
        min = std::min(last_digit, min);   
    }

    return min;
}

bool predicate_1(unsigned n)
{
    return largest_digit(n) - smallest_digit(n) == 3;
}


bool is_prime(unsigned number)
{
    bool prime{number > 1};

    for (unsigned j{2}; j <= sqrt(number) && prime; ++j)
    {
        prime = (number % j != 0);
    }

    return prime;
}

unsigned digits_sum(unsigned n)
{
    unsigned sum{0};

    for (; n != 0; n /= 10)
    {
        const unsigned last_digit{n % 10};
        sum += last_digit;
    }

    return sum;
}

bool predicate_2(unsigned n)
{
    return is_prime(digits_sum(n));
}

unsigned problem_1(unsigned n)
{
    unsigned sum{0};
    unsigned number{0};
    while (n != 0)
    {
        if (predicate_1(number))
        {
            sum += number;
            std::cout << number << '\n';
            n--;
        }

        number++;
    }

    return sum;
}

int main()
{

    std::cout << problem_1(10);
    return 0;
}