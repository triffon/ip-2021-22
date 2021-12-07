#include <iostream>
#include <cstring>

unsigned strlen2(const char str[])
{
    unsigned i{0};

    while(str[i])
    {
        ++i;
    }

    return i;
}

int strcmp2(const char lhs[], const char rhs[])
{
    unsigned i{0};
    while (lhs[i] && rhs[i] && lhs[i] == rhs[i])
    {
        ++i;
    }

    return lhs[i] - rhs[i];
}

void strcpy2(char dest[], const char source[])
{
    unsigned i{0};
    for (; source[i]; ++i)
    {
        dest[i] = source[i];
    }

    dest[i] = '\0';
}

void strcat2(char dest[], const char source[])
{
    // 'hello '
    // 'world'
    // hello world
    unsigned i{strlen2(dest)};

    for (unsigned j{0}; source[j]; ++i, ++j)
    {
        dest[i] = source[j];
    }

    dest[i] = '\0';
}

void strcpy3(char dest[], const char source[])
{
    dest[0] = '\0';
    strcat2(dest, source);
}

// return index of first occurence of character in str or -1 if it does not appear

int strchr(const char str[], char character)
{
    for (unsigned i{0}; str[i]; ++i)
    {
        if (character == str[i])
        {
            return i;
        }
    }

    return -1;
}

bool is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int atoi2(const char str[])
{
    int result{0};
    unsigned i{0};
    int sign{1};

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    for (; str[i] && is_digit(str[i]); ++i)
    {
        int digit{
            str[i] - '0'
        };

        result = result * 10 + digit;
    }

    return result * sign;
}

void run_length_encode(char destination[], const char source[])
{
    // aaaa -> 4a
    // abbccc -> a2b3c

    unsigned input{0};
    unsigned output{0};

    while (source[input])
    {
        unsigned counter{0};
        char current{source[input]};
        for (; source[input] && source[input] == current; ++input)
        {
            counter++;
        }

        std::cout << current << ' ' << counter << std::endl;

        if (counter == 1)
        {
            destination[output++] = current;
        }
        else
        {
            destination[output++] = counter + '0';
            destination[output++] = current;
        }
    }

    destination[output] = '\0';
}

int main()
{
    // cstring
    char str[101];

    std::cin.getline(str, 100); // delimiter

    char str2[101];

    run_length_encode(str2, str);

    std::cout << str2;

    return 0;
}