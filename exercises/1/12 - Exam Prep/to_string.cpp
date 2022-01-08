/*
123, 10 -> "123"
5, 2 -> "101"
5, 3 -> "12"
*/

// 5 -> 101

/*
5 / 2 -> 2(1)
2 / 2 -> 1(0)
1 / 2 -> 0(1)
*/

#include <iostream>
#include <cassert>

size_t count_digits(unsigned i, unsigned base)
{
    unsigned digits{1};

    while (i /= base)
    {
        ++digits;
    }

    return digits;
}

const char * to_string(unsigned i, unsigned base)
{
    assert(base > 0 && base <= 10);

    size_t len{
        count_digits(i, base)
    };

    char * buffer{
        new char[len + 1]{}
    };

    for (char * output_it{buffer + len - 1}; output_it >= buffer; --output_it)
    {
        unsigned remainder{i % base};

        *output_it = remainder + '0'; 

        i /= base;
    }

    return buffer;
}

int main()
{
    const char * num_str{
        to_string(123, 10)
    };

    const char * num_str2{
        to_string(5, 2)
    };

    const char * num_str3{
        to_string(5, 3)
    };

    std::cout << num_str << '\n' << num_str2 << '\n' << num_str3;

    delete [] num_str;
    delete [] num_str2;
    delete [] num_str3;

    return 0;
}