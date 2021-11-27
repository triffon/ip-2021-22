#include <iostream>

int digitsCount(int number) {
    int counter = 0;
    while (number != 0)
    {
        number /= 10;
        counter++;
    }
    return counter;
}

/*Едно число ще наричаме „съседно“, ако всеки две негови съседни цифри са различни.

Пример: 2572 е съседно, но 3119 не е.

Да се напише програма, която намира разликата на най-голямото и най-малкото „съседно“ число в интервала [a; b],
където a и b са въведени от клавиатурата естествени числа. Ако в интервала няма съседни числа, да се изведе
подходящо съобщение. Позволено е използването на масиви и функции.*/

bool isAdjacentNumber(int number)
{
    int arr[1024];
    int countDigits = digitsCount(number);
    int index = countDigits - 1;
    int copyNumber = number;
    while (copyNumber != 0)
    {
        arr[index--] = copyNumber % 10;
        copyNumber /= 10;
    }
    for (int i = 1; i < countDigits; i++)
    {
        if (arr[i - 1] == arr[i]) {
            return false;
        }
    }
    return true;
}

void execute(int a, int b)
{
    if (a > b) {
        std::cout << "Invalid interval\n";
    }
    else {
        int minAdjacent = INT_MAX;
        int maxAdjacent = INT_MIN;
        for (int i = a; i <= b; i++)
        {
            if (isAdjacentNumber(i)) {
                minAdjacent = i;
                break;
            }
        }
        for (int j = b; j >= a; j--)
        {
            if (isAdjacentNumber(j)) {
                maxAdjacent = j;
                break;
            }
        }
        if (minAdjacent == INT_MAX || maxAdjacent == INT_MIN) {
            std::cout << "No adjacent numbers\n";
        }
        else {
            std::cout << (maxAdjacent - minAdjacent);
        }
    }
}


int main()
{
    int a, b;
    std::cin >> a >> b;

    execute(a, b);

    return 0;
}