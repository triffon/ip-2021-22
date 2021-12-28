#include <iostream>

bool isPalindromeRec(char* str, int l, int r)
{
    if (l >= r)
    {
        return true;
    }

    if (str[l] != str[r])
    {
        return false;
    }

    if (l < r + 1)
    {
        return isPalindromeRec(str, l + 1, r - 1);
    }

    return true;
}

int main() {
    char str[] = { 'h', 'o', 'o' ,'d', '\0' };
    std::cout << std::boolalpha << isPalindromeRec(str, 0, 3);
    return 0;
}