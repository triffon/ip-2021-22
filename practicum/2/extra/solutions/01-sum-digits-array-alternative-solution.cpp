#include <iostream>
#include <cmath>

// Recursive implementation of the function
size_t sumDigitsRec(int num)
{
    if (num == 0)
        return 0;

    return num % 10 + sumDigitsRec(num / 10);
}

// Returns the sum of the digits of num ignoring the negative sign
size_t sumDigits(int num)
{
    return sumDigitsRec(num > 0 ? num : -num);
}

// Get the maximal sum of digits in any of the numbers
size_t maxSumDigits(const int* arr, int size)
{
    size_t maxSum = sumDigits(arr[0]);
    for (int i = 1; i < size; i++)
    {
        size_t currSum = sumDigits(arr[i]);
        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}

// Delete an allocated matrix
void cleanMatrix(int**& matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;
    matrix = nullptr;
}

/*  Prints jagged matrix given the number of rows and an array containing
 *  the number of elements on each row.
 *  ! Note that since we won't be modifying the matrix we pass it as
 *     const int * const *
 *  ! This is simillar to how we pass const arrays (const int *)
 */
void printJaggedMatrix(const int* const* matrix, int rows, const size_t* rowsElements)
{
    for (int i = 0; i < rows; i++) {
        std::cout << i << ": ";
        for (size_t j = 0; j < rowsElements[i]; j++)
            std::cout << ' ' << matrix[i][j];
        std::cout << '\n';
    }
}

//------------------------------------------------------------------------------
int main()
{
    int size;
    std::cin >> size;
    if (size <= 0)
    {
        std::cerr << "Error: Numbers count must be natural!\n";
        return 1;
    }

    // Create an array for all the numbers
    int* arr = new (std::nothrow) int[size];
    if (!arr)
    {
        std::cerr << "Not enough memory!\n";
        return 2;
    }

    // Store the numbers in the array
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    size_t maxSum = maxSumDigits(arr, size);

    // Helper array where each element will be how many numbers
    // have sum of digits equal to the index in the array
    size_t* sumCountArr = new (std::nothrow) size_t[maxSum + 1];
    if (!sumCountArr)
    {
        // Don't forget to delete all allocated memory!
        delete[] arr;
        std::cerr << "Not enough memory!\n";
        return 2;
    }

    // Nullify array
    for (int i = 0; i < maxSum + 1; i++)
        sumCountArr[i] = 0;

    // Count each number (digit sum in this case) just like in counting sort
    for (int i = 0; i < size; i++)
        ++sumCountArr[sumDigits(arr[i])];

    // Array of arrays
    int** matrix = new (std::nothrow) int*[maxSum + 1];
    if (!matrix)
    {
        // Don't forget to delete all allocated memory!
        delete[] arr;
        delete[] sumCountArr;
        std::cerr << "Not enough memory!\n";
        return 2;
    }

    // Creating each row of the matrix jagged
    for (size_t i = 0; i < maxSum + 1; i++)
    {
        if (sumCountArr[i] > 0)
        {
            matrix[i] = new (std::nothrow) int[sumCountArr[i]];

            if (!matrix[i])
            {
                // Don't forget to delete all previously allocated memory!
                cleanMatrix(matrix, i);
                delete[] arr;
                delete[] sumCountArr;
                std::cerr << "Not enough memory!\n";
                return 2;
            }
        }
        else
        {
            matrix[i] = nullptr;
        }
    }

    // Now that the jagged array is created we add the elements
    for (size_t i = 0; i < maxSum + 1; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (sumDigits(arr[j]) == i)
                matrix[i][count++] = arr[j];
        }
    }

    printJaggedMatrix(matrix, maxSum + 1, sumCountArr);

    // Don't forget to delete the allocated memory!
    delete[] arr;
    delete[] sumCountArr;
    cleanMatrix(matrix, maxSum + 1);

    return 0;
}
