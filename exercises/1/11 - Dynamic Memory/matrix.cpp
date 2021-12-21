#include <iostream>

int ** allocate_matrix(unsigned height, unsigned width)
{
    int ** matrix = new int *[height];
    for(unsigned i{0}; i < height; ++i)
    {
        matrix[i] = new int[width];
    }

    return matrix;
}

void deallocate_matrix(int ** matrix, unsigned height)
{
    for (unsigned i{0}; i < height; ++i)
    {
        delete [] matrix[i];
    }

    delete [] matrix;
}

int * allocate_matrix_v2(unsigned height, unsigned width)
{
    return new int[height * width];
}

int& element_at(int * matrix, unsigned width, unsigned i, unsigned j)
{
    return matrix[width * i + j];
}

void deallocate_matrix_v2(int * matrix)
{
    delete [] matrix;
}

int main()
{
    const unsigned size{3};
    int * matrix{
        allocate_matrix_v2(size, size)
    };

    for (unsigned i{0}; i < size; ++i)
    {
        for (unsigned j{0}; j < size; ++j)
        {
            std::cin >> element_at(matrix, size, i, j);
        }
    }

     for (unsigned i{0}; i < size; ++i)
    {
        for (unsigned j{0}; j < size; ++j)
        {
            std::cout << element_at(matrix, size, i, j) << ' ';
        }
        std::cout << '\n';
    }

    deallocate_matrix_v2(matrix);
    return 0;
}