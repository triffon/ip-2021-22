#include <iostream>
#include <utility>
#include <algorithm>

void print(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}

unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end, 
              int output_arr[], unsigned output_begin)
{
    for (; input_begin < input_end; ++input_begin)
    {
        output_arr[output_begin] = input_arr[input_begin];
        output_begin++;
    }

    return output_begin;
}


// bug here
// 1. implement without division and random access
// 2. find bug
void reverse(int arr[], unsigned begin, unsigned end)
{
    // 0 (1 2) 3 4 -> 1 3
    // 0 (2 1) 3 4

    for (unsigned i {begin}; i < end/2 + begin; ++i)
    {
        std::swap(arr[i], arr[end-i-1 + begin]);
    }
}

unsigned rotate(int arr[], unsigned begin, unsigned mid, unsigned end)
{
    /*
    reverse(arr, begin, mid);
    reverse(arr, mid, end);
    reverse(arr, begin, end);
    */

    std::reverse(arr + begin,arr+ mid);
    std::reverse(arr + mid,arr+ end);
    std::reverse(arr + begin,arr+ end);

    return begin + end - mid;
}

unsigned erase(int arr[], unsigned size, unsigned index)
{
    return copy(arr, index + 1, size, arr, index);
}

unsigned insert(int arr[], unsigned size, unsigned index, int element)
{
    arr[size] = element;
    rotate(arr, index, size, size + 1);
    return size + 1;
}

unsigned find(const int arr[], unsigned begin, unsigned end, int element)
{
    for (; begin < end; ++begin)
    {
        if (arr[begin] == element)
        {
            return begin;
        }
    }

    return end;
}

bool contains(const int arr[], unsigned begin, unsigned end, int element)
{
    return find(arr, begin, end, element) != end;
}

unsigned min_element(const int arr[], unsigned begin, unsigned end)
{
    int min{arr[begin]};
    unsigned min_index{begin};

    for (; begin != end; ++begin)
    {
        if (arr[begin] < min)
        {
            min = arr[begin];
            min_index = begin;
        }
    }

    return min_index;
}

void selection_sort(int arr[], unsigned begin, unsigned end)
{
    for (unsigned unsorted_begin{begin}; unsorted_begin < end; ++unsorted_begin)
    {
        unsigned min_index{min_element(arr, unsorted_begin, end)};
        std::swap(arr[unsorted_begin], arr[min_index]);
    }
}

unsigned merge(const int input_1[], unsigned begin_1, unsigned end_1,
               const int input_2[], unsigned begin_2, unsigned end_2,
               int output[], unsigned output_begin)
{
    while (begin_1 != end_1 && begin_2 != end_2)
    {
        if (input_1[begin_1] <= input_2[begin_2])
        {
            output[output_begin++] = input_1[begin_1++];
        }
        else
        {
            output[output_begin] = input_2[begin_2];
            begin_2++;
            output_begin++;
        }
    }

    output_begin = copy(input_1, begin_1, end_1, output, output_begin);
    return copy(input_2, begin_2, end_2, output, output_begin);
}

unsigned upper_bound(const int arr[], unsigned begin, unsigned end, int element)
{
    while (begin < end)
    {
        unsigned mid{
            (begin + end) / 2
        };

        if (element >= arr[mid])
        {
            begin = mid + 1;   
        }
        else
        {
            end = mid;
        }
    }

    return begin;
}

bool binary_search(const int arr[], unsigned begin, unsigned end, int element)
{
    unsigned greater{upper_bound(arr, begin, end, element)};
    return greater != begin && arr[greater - 1] == element;
}

void insertion_sort(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i != end; ++i)
    {
        unsigned correct_position{
            upper_bound(arr, begin, i, arr[i])
        };

        rotate(arr, correct_position, i, i + 1);
    }
}

int main()
{

    int arr[]{1, 4, 7, 0, 2};
    insertion_sort(arr, 0, 5);
    print(arr, 0, 5); // -> 0 1 2 3 4

    return 0;
}