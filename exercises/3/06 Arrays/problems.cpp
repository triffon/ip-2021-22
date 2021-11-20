#include <iostream>
#include <utility>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end, 
              int output_arr[], unsigned output_begin)
{
    for (; input_begin != input_end; ++input_begin)
    {
        output_arr[output_begin++] = input_arr[input_begin];
    }

    return output_begin;
}

void reverse(int arr[], unsigned begin, unsigned end)
{
    --end;
    for ( ; begin < end; ++begin, --end)
    {
        std::swap(arr[begin], arr[end]);
    }
}

unsigned rotate_1(int arr[], unsigned begin, unsigned mid)
{
    for (unsigned it{begin}; it != mid; ++it)
    {
        std::swap(arr[it], arr[mid]);
    }

    return begin + 1;
}

unsigned find(const int arr[], unsigned begin, unsigned end, int element)
{
    for (; begin != end; ++begin)
    {
        if (arr[begin] == element)
        {
            return begin;
        }
    }

    return end;
}

unsigned min_element(const int arr[], unsigned begin, unsigned end)
{
    unsigned min_index{begin};
    int minimum{arr[begin]};
    
    for (; begin != end; ++begin)
    {
        if (arr[begin] < minimum)
        {
            minimum = arr[begin];
            min_index = begin;
        }
    }

    return min_index;
}

void selection_sort(int arr[], unsigned begin, unsigned end)
{
    // swap
    // min_element

    // begin - начало на сортирана част
    // mid - край на сортирана / начало на несортирана
    // end - край на несоритрана

    for (unsigned mid{begin}; mid != end; ++mid)
    {
        unsigned min_index{
            min_element(arr, mid, end)
        };

        std::swap(arr[mid], arr[min_index]);
    }
}

void histogram(int arr[], unsigned begin, unsigned end)
{
    selection_sort(arr, begin, end);

    // 0 1 2 2 3 4

    unsigned count{1};
    int last{arr[begin]};
    for (unsigned it{begin + 1}; it < end; ++it)
    {
        if (last == arr[it])
        {
            ++count;   
        }
        else
        {
            std::cout << last << ": " << count << '\n';
            count = 1;
            last = arr[it];
        }
    }

    std::cout << last << ": " << count << '\n';
}

int main()
{
    int arr[]{
        1, 2, 2, 3, 2, 3
    };

    histogram(arr, 0, 6);

    return 0;
}
