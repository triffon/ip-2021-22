#include <iostream>

int main()
{
    unsigned number, digit;
    std::cout << "Моля, въведете естествено число: ";
    std::cin >> number;

    do
    {
        std::cout << "Моля, въведете цифра ";
        std::cin >> digit;
    } while (digit < 0 || digit > 9);

    unsigned origNumber = number;

    while(number > 0 && number % 10 != digit)
        // инвариант: цифрата digit не се среща в изтритите от number
        number /= 10;

    // изтрили сме всички цифри от number
    // (т.е. number == 0)
    // или
    // сме намерили цифрата digit като последна в number
    // (т.е. digit == number % 10)
    // общо: number == 0 || number % 10 == digit

    // Да допуснем, че number == 0.
    // Ако origNumber = 0 && digit == 0, отговорът трябва да е ДА
    // Ако !(origNumber = 0 && digit == 0), т.е. origNumber != 0 || digit != 0, отговорът трябва да е НЕ
    std::cout << "Цифрата " << digit;
    if (number == 0 && (origNumber != 0 || digit != 0))
        std::cout << " НЕ";
    std::cout << " се среща в записа на числото " << origNumber << std::endl;
    return 0;
}
