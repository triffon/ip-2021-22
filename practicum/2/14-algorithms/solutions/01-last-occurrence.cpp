#include <iostream>

int main()
{
    // Example array
    int size = 11;
    int arr[] = { 5, 2, 5, 7, 1, 0, -2, -3, -1, 5, 7 };

    // Finding the last occurrence of the number 5 in the array
    int toFind = 5;
    int index = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] == toFind)
            index = i;

    // Output
    if (index == -1)
        std::cout << toFind << " is not in the array." << std::endl;
    else
        std::cout << "Last occurrence of " << toFind << " is on index " << index << std::endl;

    return 0;
}
