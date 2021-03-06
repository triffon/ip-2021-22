#include <iostream>

using namespace std;

/**
 * По въведени две числа, разменете стойностите им и ги изведете на екрана.\
 * (Бонус: Без ползване на допълнителна променлива)
 */
int main()
{
    float num1, num2;
    cin >> num1 >> num2;

    cout << "Initial values:\t" << num1 << ' ' << num2 << '\n';
    // Символът '\n' е специален и задава нов ред в стандартния изход
    // Символът '\t' е специален и задава табулация в стандартния изход

    // Първи начин - чрез допълнителна променлива
    float temp = num1;  // Запазваме стойността на num1
    num1 = num2;        // В променливата num1 присвояваме стойността на num2
    num2 = temp;        // В променливата num2 присвояваме стойността на temp
                        // която пък държи първоначалната стойност на num1

    cout << "First swap:\t" << num1 << ' ' << num2 << '\n';

    // Втори начин - математика
    num1 += num2;       // Към стойността на num1 добавяме стойността на num2
    num2 = num1 - num2; // Разликата на num1 и num2 е началната стойност на num1
    num1 -= num2;       // От стойността на num1 изваждаме num2 ^

    cout << "Second swap:\t" << num1 << ' ' << num2;

    return 0;
}
