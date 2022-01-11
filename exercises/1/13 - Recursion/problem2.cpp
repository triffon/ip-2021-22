#include <iostream>
#include <cmath>

bool unique(unsigned x)
{
    bool digits[10]{false};
    // 0 - 9
    while (x)
    {
        unsigned last_digit{x % 10};
        if (digits[last_digit])
        {
            return false;
        }
        digits[last_digit] = true;
        x /= 10;
    }

    return true;
}

void test(int size)
{
    for (int diff{-size + 1}; diff < size; ++diff)
    {
        for (int i{0}; i < size; ++i)
        {
            int other_index = i + diff;
            if (other_index < 0 || other_index >= size)
            {
                continue;
            }
            
            std::cout << i << ' ' << i + diff << std::endl;
        }
    }
}

/*
00 01 02
10 11 12
20 21 22

-> 20
-> 10 21
-> 00 11 22
-> 01 12
-> 02
*/

int main()
{
    test(3);
    return 0;
}