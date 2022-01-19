#include <iostream>

// Sorts an array with elements in [0, 100] by frequency
void frequencySort(short arr[], int size);
// Returns the index of the first greatest element in the array
unsigned getGreatestIndex(short arr[], int size);
// Prints the array
void printArr(short arr[], int size);

const int MAX_SIZE = 1024;
const short MAX_VALUE = 100;

int main()
{

    short arr[MAX_SIZE];
    int size;
    std::cout << "Enter the array size: ";
    std::cin >> size;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 100) {
            std::cout << "Error! Elements must be in the range [0, 100]!" << std::endl;
            return 1;
        }
    }

    frequencySort(arr, size);

    printArr(arr, size);

    return 0;
}




void frequencySort(short arr[], int size)
{
    // Using the counting sort technique with the additional
    // array and storing the frequencies of the elements

    short freqArr[MAX_VALUE + 1] = {0, };

    for (int i = 0; i < size; i++)
        freqArr[arr[i]]++;

    int counter = 0;
    while (counter < size) {

        int maxFreqIndex = getGreatestIndex(freqArr, MAX_VALUE + 1);

        for (int i = 0; i < freqArr[maxFreqIndex]; i++)
            arr[counter++] = maxFreqIndex;

        freqArr[maxFreqIndex] = 0;

    }

}


unsigned getGreatestIndex(short arr[], int size)
{
    unsigned result = 0;
    for (int i = 1; i < size; i++)
        if (arr[result] < arr[i])
            result = i;

    return result;
}


void printArr(short arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
}
