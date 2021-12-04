#include <iostream>

unsigned length(const char str[])
{
    unsigned i = 0;
    while (str[i])
    {
        ++i;
    }

    return i;
}

int compare(const char first[], const char second[])
{
    unsigned i = 0;
    while (first[i] && first[i] == second[i])
    {
        ++i;
    }

    return first[i] - second[i];
}

bool isLowerCaseLetter(char c)
{
    return c >= 'a' && c <= 'z';
}

char toUpperCaseLetter(char c)
{
    if (isLowerCaseLetter(c))
    {
        return c - 'a' + 'A';
    }

    return c;
}

void convertToUpper(char str[])
{
    unsigned i = 0;
    while (str[i])
    {
        str[i] = toUpperCaseLetter(str[i]);
        ++i;
    }
}

int main()
{
    const int MAX_SIZE = 100;

    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    std::cout << "The length of " << str << " is " << length(str) << std::endl;

    char another[MAX_SIZE];
    std::cin.getline(another, MAX_SIZE);

    unsigned result = compare(str, another);
    if (result < 0)
    {
        std::cout << str << " < " << another << std::endl;
    }
    else if(result == 0)
    {
        std::cout << str << " == " << another << std::endl;
    }
    else
    {
        std::cout << str << " > " << another << std::endl;
    }

    convertToUpper(str);
    std::cout << "To upper: " << str << std::endl;

    return 0;
}