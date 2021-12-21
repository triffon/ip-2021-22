#include <iostream>
#include <algorithm>

void print(const int * first, const int * last)
{
    for (; first < last; ++first)
    {
        std::cout << *first << ' ';
    }

    std::cout << std::endl;
}

int * expand(int *& first, int *& last, int *& capacity)
{
    long int data_length{capacity - first};
    long int memory_length{data_length * 2};
    int * new_first{new int[memory_length]};

    std::copy(first, last, new_first);

    last = new_first + data_length;
    capacity = new_first + memory_length;

    delete [] first;

    first = new_first;

    return first;
}

int * append(int *& first, int *& last, int *& capacity, int element)
{
    if (last == capacity)
    {
        std::cout << "allocating" << std::endl;
        first = expand(first, last, capacity);
    }

    *last++ = element;

    return first;
}

int main()
{
    unsigned size;
    std::cin >> size;
    unsigned capacity{size + 1};

    int * arr = new int[capacity];

    int * last{arr + size};
    int * capacity_end{arr + capacity};

    for (unsigned i{0}; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "size " << last - arr << std::endl;

    print(arr, last);

    append(arr, last, capacity_end, 10);

    std::cout << "size " << last - arr << std::endl;

    print(arr, last);

    append(arr, last, capacity_end, 20);
    std::cout << "size " << last - arr << std::endl;

    print(arr, last);

    delete [] arr;

    return 0;
}