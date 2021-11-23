#include <iostream>

bool is_suffix(int n, int k)
{
    if (n == k)
    {
        return false;
    }

    if (k == 0)
    {
        return n % 10 == 0;
    }

    for (; k > 0; k /= 10, n /= 10)
    {
        int last_digit_n{
            n % 10
        };

        int last_digit_k{
            k % 10
        };

        if (last_digit_n != last_digit_k) {
            return false;
        }
    }

    return true;
}

bool is_infix(int n, int k)
{
    n /= 10;

    while (n > 0 && !is_suffix(n, k))
    {
        n /= 10;
    }

    return n > 0;
}

bool is_adjacent(int n)
{
    int last_digit{n % 10};
    n /= 10;

    for (; n > 0; n /= 10)
    {
        int digit{n % 10};

        if (digit == last_digit)
        {
            return false;
        }

        last_digit = digit;
    }

    return true;
}

int get_first_adjacent(int a, int b)
{
    for (; a <= b; ++a)
    {
        if (is_adjacent(a))
        {
            return a;
        }
    }

    return -1;
}

int get_last_adjacent(int a, int b)
{
    for (; b >= a; --b)
    {
        if (is_adjacent(b))
        {
            return b;
        }
    }

    return -1;
}

void task_2(int a, int b)
{
    if (a > b || a < 0 || b < 0) {
        std::cout << "error\n";
        return;
    }

    int min_adjacent{
        get_first_adjacent(a, b)
    };

    int max_adjacent{
        get_last_adjacent(a, b)
    };

    if (min_adjacent == -1)
    {
        std::cout << "No adjacent numbers\n";
    }
    else
    {
        std::cout << max_adjacent - min_adjacent << '\n';    
    }
}

void print_rotation(char arr[], unsigned size, unsigned start)
{
    for (unsigned i{0}; i < size; ++i, start = (start + 1) % size)
    {
        std::cout << arr[start];
    }
}

bool compare_rotation(char first_arr[], unsigned size_1, unsigned start_1,
                      char second_arr[], unsigned size_2, unsigned start_2)
{
    unsigned i{0};
    for (; i < size_2; ++i, ++start_1, start_2 = (start_2 + 1) % size_2)
    {
        if (start_1 >= size_1 || first_arr[start_1] != second_arr[start_2])
        {
            return false;
        }
    }

    return i == size_2;
}

void task_3(char first_arr[], unsigned size_1, char second_arr[], unsigned size_2)
{
    for (unsigned start_2{0}; start_2 < size_2; ++start_2)
    {
        for (unsigned start_1{0}; start_1 < size_1; ++start_1)
        {
            if (compare_rotation(first_arr, size_1, start_1, second_arr, size_2, start_2))
            {
                std::cout << "Rotation \"";
                print_rotation(second_arr, size_2, start_2);
                std::cout << "\" found after deleting " << start_1 << " characters from the beginning and " << size_1 - start_1 - size_2 << " characters from the end\n";
                return;
            }
        }
    }

    std::cout << "No rotation found\n";
}

void print_deleted(char first_arr[], unsigned size_1, char second_arr[], unsigned size_2, unsigned start_2)
{
    for (unsigned start_1{0}; start_1 < size_1; ++start_1)
    {
        if (first_arr[start_1] != second_arr[start_2])
        {
            std::cout << start_1 << ' ';
        }
        else
        {
            start_2 = (start_2 + 1) % size_2;
        }
    }
}

void bonus(char first_arr[], unsigned size_1, char second_arr[], unsigned size_2)
{
    for (unsigned start_2{0}; start_2 < size_2; ++start_2)
    {
        unsigned current{start_2};
        unsigned found_letters{0};

        for (unsigned start_1{0}; start_1 < size_1; ++start_1)
        {
            if (first_arr[start_1] == second_arr[current])
            {
                current = (current + 1) % size_2;
                ++found_letters;
            }

            if (found_letters == size_2)
            {
                std::cout << "Rotation \"";
                print_rotation(second_arr, size_2, start_2);
                std::cout << "\" found after deleting ";
                print_deleted(first_arr, size_1, second_arr, size_2, start_2);
                std::cout << '\n';
                return;
            }
        }
    }

    std::cout << "No rotation found\n";
}

int main()
{
    char first_arr_3[]{'a', 'x', 'z', 't', 'c', 'y'};
    char second_arr_3[]{'c', 'a', 't'};

    char first_arr_4[]{'c', 'm', 'd', 'a', 'i', 'h', 'n', 'b', 'a'};
    char second_arr_4[]{'a', 'd', 'h', 'p'};
    bonus(first_arr_3, 6, second_arr_3, 3);
    bonus(first_arr_4, 9, second_arr_4, 4);

    return 0;
}
