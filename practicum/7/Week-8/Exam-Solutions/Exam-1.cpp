#include <iostream>
#include <cmath>

int digitsCount(int number) {
    int counter = 0;
    while (number != 0)
    {
        number /= 10;
        counter++;
    }
    return counter;
}

/*Конкатенация на две естествени числа A и B наричаме число A ∘ B, което се получава като към цифрите на A се долепят цифрите на B.
Пример:
123 ∘ 431 = 123431
123 ∘ 0 = 1230

Да се напише програма, която въвежда две естествени числа N и K и извежда дали съществуват естествени числа А и B, такива че N = A ∘ K ∘ B.
За реализацията на задача може да се използва и функция с два параметъра – N и К.
В решението на задачата не се допуска използването на масиви!*/


bool valid(int n, int k)
{
    while (n > k)
    {
        int specialPercent = pow(10, digitsCount(k));
        if ((n % specialPercent) == k) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << digitsCount(1234);
    std::cout << std::boolalpha << valid(n / 10, k);
}