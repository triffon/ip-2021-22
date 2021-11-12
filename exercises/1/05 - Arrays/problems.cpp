#include <iostream>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (; begin != end; ++begin)
    {
        std::cout << arr[begin] << ' ';
    }
    std::cout << '\n';
}

void reverse(int arr[], unsigned begin, unsigned end)
{
    for (; begin != end && begin != --end; ++begin)
    {
        std::swap(arr[begin], arr[end]);
    }
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

unsigned rotate(int arr[], unsigned begin, unsigned mid, unsigned end)
{
    reverse(arr, begin, mid);
    reverse(arr, mid, end);
    reverse(arr, begin, end);

    return begin + end - mid;
}

unsigned erase(int arr[], unsigned size, unsigned index)
{
    return rotate(arr, index, index + 1, size); 
}

unsigned insert(int arr[], unsigned size, unsigned index, int element)
{
    arr[size] = element;
    rotate(arr, index, size, size + 1);
    return size + 1;
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

    return begin;
}

bool contains(const int arr[], unsigned begin, unsigned end, int element)
{
    return find(arr, begin, end, element) != end;
}

unsigned min_element(const int arr[], unsigned begin, unsigned end)
{
    unsigned min_index{begin};
    int minimum{arr[min_index]};

    for(; begin != end; ++begin)
    {
        if (arr[begin] < minimum)
        {
            minimum = arr[begin];
            min_index = begin;
        }
    }

    return min_index;
}

int main()
{
    return 0;
}