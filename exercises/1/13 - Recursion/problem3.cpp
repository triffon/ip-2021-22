#include <iostream>
#include <algorithm>

// implement find

int get_value(const char * letters_first, const char * letters_last, const int * values_first, char var)
{
    const char * pos{
        std::find(letters_first, letters_last, var)
    };

    if (pos == letters_last)
    {
        return 0;
    }

    int index = pos - letters_first;

    return values_first[index];
}

int calculate(const char * expression, const char * letters_first, const char * letters_last, const int * values_first)
{
    int product{1};
    int sum{0};

    for (; *expression; ++expression)
    {
        char symbol{*expression};

        if (symbol >= 'a' && symbol <= 'z')
        {
            product *= get_value(letters_first, letters_last, values_first, symbol);
        }
        else if (symbol == '+')
        {
            sum += product;
            product = 1;
        }
    }

    return sum + product;
}

int main()
{
    char letters[]{'b', 'c', 'a', 'd'};
    int values[]{5, 3, 2, 42};

    std::cout << calculate("a.b+b.c+d+a.c", letters, letters + 4, values);

    return 0;
}