#include <iostream>

int main()
{
    int number;
    std::cout << "Моля, въведете цяло число: ";
    std::cin >> number;

    int origNumber = number, symNumber = 0;

    while(number != 0) {
        // инвариант: symNumber е симетричното число, на числото, получено от изтритите от number цифри
        symNumber = symNumber * 10 + number % 10;
        number /= 10;
    }

    std::cout << "Симетричното число на " << origNumber << " е " << symNumber;
    if (origNumber == symNumber)
        std::cout << " и затова е палиндром";
    std::cout << std::endl;

    return 0;
}
