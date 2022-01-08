#include <iostream>

const size_t max_size{3};

double average(const int * first, const int * last)
{
    double sum{0};
    size_t counter{0};
    for (; first != last; ++first)
    {
        sum += *first;
        ++counter;
    }

    return counter ? sum / counter : counter;
}

const double * averages(const int matrix[][max_size], size_t rows)
{
    double * matrix_averages{new double[rows]};

    for (size_t i{0}; i < rows; ++i)
    {
        matrix_averages[i] = average(matrix[i], matrix[i] + max_size);
    }

    return matrix_averages;
}

void print(const double * first, const double * last)
{
    for (; first != last; ++first)
    {
        std::cout << *first << ' ';
    }
}

int main()
{
    const size_t rows{3};

    int matrix[][max_size] {
        { 1, 1, 1, },
        { 1, 2, 3, },
        { 1, 10, 23 }, 
    };

    const double * matrix_averages{averages(matrix, rows)};

    print(matrix_averages, matrix_averages + rows);

    delete [] matrix_averages;

    return 0;
}