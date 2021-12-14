#include <iostream>

const unsigned max_size{100};

void print(const int arr[][max_size], unsigned rows, unsigned columns)
{
    for (unsigned i{0}; i < rows; ++i)
    {
        for (unsigned j{0}; j < columns; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void print_by_columns(const int arr[][max_size], unsigned rows, unsigned columns)
{
    for (unsigned j{0}; j < columns; ++j)
    {
        for (unsigned i{0}; i < rows; ++i)
        {
            std::cout << arr[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void transpose(const int arr[][max_size], unsigned rows, unsigned columns, int arr_t[][max_size])
{
    for (unsigned j{0}; j < columns; ++j)
    {
        for (unsigned i{0}; i < rows; ++i)
        {
            arr_t[i][j] = arr[j][i];
        }
    }
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

unsigned min_elements(
    const int arr[max_size][max_size], unsigned rows, unsigned columns,
    int output_begin[], unsigned first
)
{
    for (unsigned i{0}; i < rows; ++i)
    {
        
        output_begin[first++] = arr[i][min_element(arr[i], 0, columns)];
    }

    return first;
}

void add(const int a[max_size][max_size], const int b[max_size][max_size], unsigned rows, unsigned columns,
         int res[max_size][max_size])
{
    for (unsigned i{0}; i < rows; ++i)
    {
        for (unsigned j{0}; j < columns; ++j)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply(const int a[][max_size], unsigned a_rows, unsigned a_columns,
              const int b[][max_size], unsigned b_columns,
              int res[][max_size])
{
    for (unsigned i{0}; i < a_rows; ++i)
    {
        for (unsigned j{0}; j < b_columns; ++j)
        {
            for (unsigned k{0}; k < a_columns; ++k)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void spiral(const int arr[][max_size], unsigned size)
{
    for (unsigned start{0}; size > start; --size, ++start)
    {
        for (unsigned i{start}; i < size; ++i)
        {
            std::cout << arr[start][i] << ' ';
        }

        for (unsigned i{start + 1}; i < size; ++i)
        {
            std::cout << arr[i][size - 1] << ' ';
        }

        for (unsigned i{size - 2}; i > start; --i)
        {
            std::cout << arr[size - 1][i] << ' ';
        }

        for (unsigned i{size - 1}; i > start; --i)
        {
            std::cout << arr[i][start] << ' ';
        }
    }

    // return first;
}


int main()
{
    const int sp4[][max_size]{
        { 1,  2,  3,  4, 5},
        {16, 17, 18,  19, 6},
        {15, 24, 25,  26, 7},
        {14, 23,  22,  21, 8},
        {13, 12, 11, 10, 9}
    };

    spiral(sp4, 5);

    
    return 0;
}