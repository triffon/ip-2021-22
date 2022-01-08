#include <iostream>
#include <cstring>

// "hello world 123" -> prints: 123 world hello

// "hello\0"

// create a string that contains the same words in reverse order

const char * find_last(const char * first, const char * last, char c)
{
    for (--last; last >= first; --last)
    {
        if (*last == c)
        {
            return last;
        }
    }

    return last;
}

char * copy(const char * input_first, const char * input_last, char * output_first)
{
    for (; input_first != input_last; ++input_first)
    {
        *output_first = *input_first;
        ++output_first;
    }

    return output_first;
}

void print(const char * first, const char * last)
{
    for (; first != last; ++first)
    {
        std::cout << *first;
    }
}

char * reverse_words(const char * sentence)
{
    size_t len{strlen(sentence)};
    char * buffer{new char[len + 1]};
    char * buffer_output{buffer};

    const char * end = sentence + len;

    while (sentence < end)
    {
        const char * last_space{
            find_last(sentence, end, ' ')
        };

        buffer_output = copy(last_space + 1, end, buffer_output);

        if (last_space > sentence) {
            *buffer_output = ' ';
            ++buffer_output;
        }
        
        end = last_space;
    }

    *buffer_output = '\0';
    return buffer;
}

int main()
{
    char * reversed{
        reverse_words("hello world kappa")
    };

    std::cout << reversed;

    delete [] reversed;

    return 0;
}