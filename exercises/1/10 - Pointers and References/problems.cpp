int * expand(int * first, int *& last, int *& capacity)
{
    long int data_length{capacity - first};
    long int memory_length{data_length + 1};
    int * new_first{new int[memory_length]};

    std::copy(first, last, new_first);

    last = new_first + data_length;
    capacity = new_first + memory_length;

    delete [] first;

    return new_first;
}

int * append(int * first, int *& last, int *& capacity, int element)
{
    if (last == capacity)
    {
        first = expand(first, last, capacity);
    }

    *last++ = element;

    return first;
}