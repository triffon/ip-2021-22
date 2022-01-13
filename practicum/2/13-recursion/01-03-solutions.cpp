#include <iostream>
using namespace std;

/// 1. Напишете рекурсивна функция, която по подадено цяло число num извежда на конзолата числата от num до 1.
void printNumToOne(int number)
{
    if(number < 1)
        return;

    cout << number << ' ';
    printNumToOne(number - 1);
}

/// 2. Напишете рекурсивна функция, която по подадено цяло число num извежда на конзолата числата от 1 до num.
void printOneToNumber(int number)
{
    if(number < 1)
        return;

    printOneToNumber(number - 1);
    cout << number << ' ';
}

/// 3. Напишете рекурсивна функция, която по подаден масив и размер връща най-голямото число в масива.
int findMax(const int *arr, int size)
{
    if(size <= 0)
        return -1;
    if(size == 1)
    {
        return arr[0];
    }
    else
    {
        return max(arr[size - 1], findMax(arr, size - 1));
    }
}


int main()
{
	int arr[] = {2, 5, 7, 3, 4};

    cout << findMax(arr, 5);

	return 0;
}
