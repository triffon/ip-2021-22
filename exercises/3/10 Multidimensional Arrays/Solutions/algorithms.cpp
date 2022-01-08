#include "algorithms.h"

#include <iostream>

bool isMember(int array[], int n, int element)
{
    for (int i = 0; i < n; ++i)
    {
        if (array[i] == element)
            return true;
    }

    return false;
}

int findIndexOfMin(int array[], int n, int start)
{
    if (start >= n)
        return -1;

    int minIndex = start;
    for (int i = start + 1; i < n; ++i)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }

    return minIndex;
}

void sort(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = findIndexOfMin(array, n, i);

        if (minIndex != i)
            std::swap(array[i], array[minIndex]);
    }
}

int findElementsPosition(int array[], int n, int element)
{
    int left = 0;
    int right = n;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (array[middle] == element)
            return middle;

        if (array[middle] < element)
            left = middle + 1;
        else
            right = middle - 1;
    }

    // the element has not been found
    return -1;
}

void findSet(int array[], int n, int set[], int& count)
{
    for (int i = 0; i < n; ++i)
    {
        if (!isMember(set, count, array[i]))
        {
            set[count] = array[i];
            ++count;
        }
    }
}