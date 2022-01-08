#include <iostream>

unsigned count(const int * first, const int * last, int element)
{
    unsigned counter{0};
    for (; first != last; ++first)
    {
        counter += (*first == element);
    }

    return counter;
}

bool is_permutation(
    const int * first_1, const int * last_1,
    const int * first_2, const int * last_2)
{
    for (const int * first{first_1}; first != last_1; ++first)
    {
        unsigned count_1{
            count(first_1, last_1, *first)
        };

        unsigned count_2{
            count(first_2, last_2, *first)
        };

        if (count_1 != count_2)
        {
            return false;
        }
    }

    return true;
}

int * min_element(int * first, int * last)
{
    int * min_pointer{first};

    for (; first != last; ++first)
    {
        if (*first < *min_pointer)
        {
            min_pointer = first;
        }
    }

    return min_pointer;
}

void selection_sort(int * first, int * last)
{
    for (int * unsorted_first{first}; unsorted_first != last; ++unsorted_first)
    {
        int * min_index{
            min_element(unsorted_first, last)
        };

        std::iter_swap(unsorted_first, min_index);
    }
}

bool equal(
    const int * first_1, const int * last_1,
    const int * first_2, const int * last_2)
{
    for (; first_1 != last_1 && first_2 != last_2; ++first_1, ++first_2)
    {
        if (*first_1 != *first_2)
        {
            return false;
        }
    }

    return first_1 == last_1 && first_2 == last_2;
}

bool is_permutation2(
    int * first_1, int * last_1,
    int * first_2, int * last_2)
{
    selection_sort(first_1, last_1);
    selection_sort(first_2, last_2);
    return equal(first_1, last_1, first_2, last_2);
}

int main()
{
    int arr[]{
        1, 2, 3, 1
    };

    int arr2[]{
        1, 3, 1, 2
    };

    int arr3[]{
        1, 3, 2, 2
    };

    std::cout << std::boolalpha << is_permutation2(arr, arr + 4, arr, arr + 4);
    std::cout << std::boolalpha << is_permutation2(arr, arr + 4, arr2, arr2 + 4);
    std::cout << std::boolalpha << is_permutation2(arr, arr + 4, arr3, arr3 + 4);
    return 0;
}