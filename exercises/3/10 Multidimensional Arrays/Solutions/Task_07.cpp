#include "algorithms.h"
#include "io.h"

#include <iostream>

// зад. 7
bool areSetsEqual(int first[], int countFirst, int second[], int countSecond)
{
    if (countFirst != countSecond)
        return false;

    for (int i = 0; i < countFirst; ++i)
    {
        if (!isMember(second, countSecond, first[i]))
            return false;
    }

    return true;
}

bool hasSimilarRows(int matrix[][MAX_SIZE], int n, int m)
{
    int setFirstRow[MAX_SIZE];
    int countFirstSet = 0;

    int setSecondRow[MAX_SIZE];
    int countSecondSet = 0;

    for (int i = 0; i < n; ++i)
    {
        findSet(matrix[i], m, setFirstRow, countFirstSet);

        for (int j = i + 1; j < n; ++j)
        {
            findSet(matrix[j], m, setSecondRow, countSecondSet);

            if (areSetsEqual(setFirstRow, countFirstSet, setSecondRow, countSecondSet))
                return true;
        }
    }

    return false;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    
    read(matrix, 4, 5);
    std::cout
        << "Are there similar rows? "
        << std::boolalpha << hasSimilarRows(matrix, 4, 5) << std::endl;

    return 0;
}
