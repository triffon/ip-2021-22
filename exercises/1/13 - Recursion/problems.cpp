#include <iostream>

// strcmp2

int get_code(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return c;
    }

    return 0;
}

int strcmp2(const char * lhs, const char * rhs)
{
    unsigned i{0};
    while (get_code(lhs[i]) && get_code(rhs[i]) && get_code(lhs[i]) == get_code(rhs[i]))
    {
        ++i;
    }

    return get_code(lhs[i]) - get_code(rhs[i]);
}

const char * minWord(const char * sentence)
{
    const char * min_ptr{nullptr};
    bool word_start{true};
    while (*sentence)
    {
        if (get_code(*sentence) != 0 && word_start)
        {
            // new word starts here
            if (!min_ptr || strcmp2(sentence, min_ptr) < 0)
            {
                min_ptr = sentence;
            }
        }

        if (get_code(*sentence))
        {
            word_start = false;
        }
        else
        {
            word_start = true;
        }

        ++sentence;
    }

    return min_ptr;
}

int main()
{
    std::cout << minWord("this sentence is false.");
    return 0;
}
