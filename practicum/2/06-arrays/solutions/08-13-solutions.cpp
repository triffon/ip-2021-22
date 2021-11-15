#include <iostream>

/**
 * @author Dako Dimov
 */

const int MAX_ARRAY_SIZE = 128;

void Sum42(const int arr[], int size);
void FillArray(int arr[], int size);
void PrintArray(const int arr[], int size);
void Find(const int arr[], int size, int target, int &first, int &last, int &count);
bool IsSaw(const int arr[], int size);
void LargestSubset(const int arr[], int size, int &begin, int &length);
void PolynomialProduct(int result[], int &resultSize, const int pol1[], int size1, const int pol2[], int size2);
bool SumOfZero(const int arr[], int size);
void PrintPolynomial(const int arr[], int size);

using namespace std;

int main()
{

    int elementsCount = 0;
    int arr[MAX_ARRAY_SIZE];
    int resultArr[MAX_ARRAY_SIZE];
    int arr2[MAX_ARRAY_SIZE];
    int arr3[MAX_ARRAY_SIZE];

    // Task 8
    std::cin >> elementsCount;
    FillArray(arr, elementsCount);
    Sum42(arr, elementsCount);
/*
    // Task 9
    int target, count, first, last;
    cin >> elementsCount;
    FillArray(arr, elementsCount);
    cin >> target;
    Find(arr, elementsCount, target, first, last, count);
    cout << "First: " << first << " last: " << last << " count: " << count << '\n';
/*
    // Task 10
    cin >> elementsCount;
    FillArray(arr, elementsCount);
    cout << (IsSaw(arr, elementsCount) ? "Yes" : "No") << '\n';

    // Task 11
    cin >> elementsCount;
    FillArray(arr, elementsCount);
    LargestSubset(arr, elementsCount, first, count);
    cout << "Beginning: " << first << " lenght: " << count << '\n';

    // Task 12
    int arr2Size, arr3Size;
    cout << "Enter polynomial size: ";
    cin >> arr2Size;
    cout << "Enter coeficcients: ";
    FillArray(arr2, arr2Size);
    cout << "Enter polynomial size: ";
    cin >> arr3Size;
    cout << "Enter coeficcients: ";
    FillArray(arr3, arr3Size);
    int resultArrSize;
    PolynomialProduct(resultArr, resultArrSize, arr2, arr2Size, arr3, arr3Size);
    PrintPolynomial(resultArr, resultArrSize);

    // Task 13
    cin >> elementsCount;
    FillArray(arr, elementsCount);
    SumOfZero(arr, elementsCount);
*/
    return 0;
}

void Sum42(const int arr[], int size)
{
    for (int first = 0; first < size - 1; first++)
    {
        for (int second = first + 1; second < size; second++)
        {
            if (arr[first] + arr[second] == 42)
            {
                std::cout << '(' << arr[first] << ", " << arr[second] << ") ";
            }
        }
    }
}

void FillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void PrintArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void Find(const int arr[], int size, int target, int &first, int &last, int &count)
{
    bool foundFirst = false;
    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            last = i;
            count++;
            if (!foundFirst)
            {
                first = i;
                foundFirst = true;
            }
        }
    }
}

bool IsSaw(const int arr[], int size)
{
    if (size > 3)
    {

        for (int i = 0; i < size - 2; i++)
        {
            if ((arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2]) ||
                (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2]))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}

void LargestSubset(const int arr[], int size, int &begin, int &length)
{
    begin = -1;
    int currentLen = 0, longestLen = 0;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            currentLen++;
        }
        else
        {
            if (currentLen > longestLen)
            {
                begin = i - currentLen;
                longestLen = currentLen;
            }

            currentLen = 0;
        }
    }
    if (currentLen > longestLen)
    {
        longestLen = currentLen;
    }
    length = longestLen + 1;
}

void PolynomialProduct(int result[], int &resultSize, const int pol1[], int size1, const int pol2[], int size2)
{
    resultSize = size1 + size2 - 1;
    for (int i = 0; i < resultSize; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            result[i + j] += pol1[i] * pol2[j];
        }
    }
}

bool SumOfZero(const int arr[], int size)
{
    for (int start = 0; start < size; start++)
    {
        int sum = 0;

        for (int i = start; i < size; i++)
        {
            sum += arr[i];

            if (sum == 0)
                return true;
        }
    }
    return false;
}

void PrintPolynomial(const int arr[], int size)
{
    if ( size <= 0 )
        return;

    if ( size > 1 )
        cout << arr[0] << "*x^" << size - 1;
    else
        cout << arr[0];

    for ( int i = 1; i < size - 1; i++ )
    {
        if ( arr[ i ] < 0 )
            cout << " - " << -arr[i] << "*x^" << size - i - 1;
        else
            cout << " + " << arr[i] << "*x^" << size - i - 1;
    }

    if ( size > 1 )
    {
        if ( arr[size - 1] > 0 )
            cout << " + " << arr[size - 1];
        else
            cout << " - " << -arr[size - 1];
    }
}
